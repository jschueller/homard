# -*- coding: utf-8 -*-
# Copyright (C) 2011-2014  CEA/DEN, EDF R&D
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#
"""
Python script for HOMARD
Copyright EDF-R&D 2010, 2014
Test test_11 associe au tutorial 2
"""
__revision__ = "V2.2"

#========================================================================
Test_Name = "test_12"
n_iter_test_file = 2
#========================================================================
import os
import tempfile
import sys
import HOMARD
import salome
#
# ==================================
pathHomard = os.getenv('HOMARD_ROOT_DIR')
# Repertoire des donnees du test
Rep_Test = os.path.join(pathHomard, "share", "salome", "resources", "homard")
Rep_Test = os.path.normpath(Rep_Test)
sys.path.append(Rep_Test)
from test_util import test_results
# Repertoire des resultats
dircase = tempfile.mkdtemp()
# Repertoire des donnees du tutorial
data_dir = os.path.join(pathHomard, "share", "doc", "salome", "gui", "HOMARD", "fr", "_downloads")
data_dir = os.path.normpath(data_dir)
sys.path.append(data_dir)
from tutorial_util import gzip_gunzip
# ==================================
gzip_gunzip(data_dir, 2, -1)
# ==================================

salome.salome_init()
import iparameters
ipar = iparameters.IParameters(salome.myStudy.GetCommonParameters("Interface Applicative", 1))
ipar.append("AP_MODULES_LIST", "Homard")
#
#========================================================================
#========================================================================
def homard_exec(theStudy):
  """
Python script for HOMARD
  """
  #
  homard.SetCurrentStudy(theStudy)
  #
  # Creation des zones
  # ==================
  # Box "Zone_0"
  Zone_0 = homard.CreateZoneBox ('Zone_0', -0.1, 1.1, -0.1, 1.1, 0.9, 1.1)
  #
  # Sphere "Zone_1"
  Zone_1 = homard.CreateZoneSphere ('Zone_1', 0., 0., 0., 1.05)
  #
  # Box "Zone_2"
  Zone_2 = homard.CreateZoneBox ('Zone_2', -0.1, 0.51, -0.1, 0.51, -0.1, 0.51)
  #
  # Hypothese "Hypo_2"
  # ==================
  Hypo_2 = homard.CreateHypothesis('Hypo_2')
  Hypo_2.AddZone('Zone_1', 1)
  Hypo_2.AddZone('Zone_0', 1)
  #
  # Hypothese "Hypo_2_bis"
  # ======================
  Hypo_2_bis = homard.CreateHypothesis('Hypo_2_bis')
  Hypo_2_bis.AddZone('Zone_0', -1)
  Hypo_2_bis.AddZone('Zone_2', 1)
  #
  # Cas
  # ===
  Case_2 = homard.CreateCase('Case_2', 'MZERO', data_dir+'/tutorial_2.00.med')
  Case_2.SetDirName(dircase)
  #
  # Iteration "Iter_2_1"
  # ====================
  Iter_2_1 = Case_2.NextIteration('Iter_2_1')
  Iter_2_1.SetMeshName('M_1')
  Iter_2_1.SetMeshFile(dircase+'/maill.01.med')
  Iter_2_1.AssociateHypo('Hypo_2')
  error = Iter_2_1.Compute(1, 2)
  #
  # Iteration "Iter_2_2"
  # ====================
  Iter_2_2 = Iter_2_1.NextIteration('Iter_2_2')
  Iter_2_2.SetMeshName('M_2')
  Iter_2_2.SetMeshFile(dircase+'/maill.02.med')
  Iter_2_2.AssociateHypo('Hypo_2_bis')
  error = Iter_2_2.Compute(1, 2)
  #
  return error

#========================================================================

homard = salome.lcc.FindOrLoadComponent('FactoryServer', 'HOMARD')
assert homard is not None, "Impossible to load homard engine"
homard.SetLanguageShort("fr")
#
# Exec of HOMARD-SALOME
#
try :
  error_main = homard_exec(salome.myStudy)
  if error_main :
    raise Exception('Pb in homard_exec at iteration %d' %error_main )
except Exception, e:
  raise Exception('Pb in homard_exec: '+e.message)
#
# Test of the results
#
n_rep_test_file = n_iter_test_file
test_results(Rep_Test, Test_Name, dircase, n_iter_test_file, n_rep_test_file)
#
# ==================================
gzip_gunzip(data_dir, 2, 1)
# ==================================
#
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
  iparameters.getSession().restoreVisualState(1)

