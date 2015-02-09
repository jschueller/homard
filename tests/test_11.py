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
Test test_11 associe au tutorial 1
"""
__revision__ = "V2.2"

#========================================================================
Test_Name = "test_11"
n_iter_test_file = 3
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
gzip_gunzip(data_dir, 1, -1)
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
  # Hypotheses
  # ==========
  Hypo_1 = homard.CreateHypothesis('Hypo_1')
  Hypo_1.SetUnifRefinUnRef(1)
  #
  # Cas
  # ===
  Case_1 = homard.CreateCase('Case_1', 'MAILL', data_dir+'/tutorial_1.00.med')
  Case_1.SetDirName(dircase)
  Case_1.SetConfType(1)
  #
  # Iterations
  # ==========
  # Iteration "Iter_1_1"
  Iter_1_1 = Case_1.NextIteration('Iter_1_1')
  Iter_1_1.SetMeshName('MESH')
  Iter_1_1.SetMeshFile(dircase+'/maill.01.med')
  Iter_1_1.AssociateHypo('Hypo_1')
  error = Iter_1_1.Compute(1, 2)

  # Iteration "Iter_1_2"
  Iter_1_2 = Iter_1_1.NextIteration('Iter_1_2')
  Iter_1_2.SetMeshName('MESH')
  Iter_1_2.SetMeshFile(dircase+'/maill.02.med')
  Iter_1_2.AssociateHypo('Hypo_1')
  error = Iter_1_2.Compute(1, 2)

  # Iteration "Iter_1_3"
  Iter_1_3 = Iter_1_2.NextIteration('Iter_1_3')
  Iter_1_3.SetMeshName('MESH')
  Iter_1_3.SetMeshFile(dircase+'/maill.03.med')
  Iter_1_3.AssociateHypo('Hypo_1')
  error = Iter_1_3.Compute(1, 2)
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
gzip_gunzip(data_dir, 1, 1)
# ==================================
#
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
  iparameters.getSession().restoreVisualState(1)

