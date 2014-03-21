# -*- coding: iso-8859-1 -*-
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
Test test_11 associe au tutorial 3
"""
__revision__ = "V2.1"

#========================================================================
Test_Name = "test_13"
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
dircase = tempfile.mktemp()
os.mkdir(dircase)
# Repertoire des donnees du tutorial
data_dir = os.path.join(pathHomard, "share", "doc", "salome", "gui", "HOMARD", "fr", "_downloads")
data_dir = os.path.normpath(data_dir)
sys.path.append(data_dir)
from tutorial_util import gzip_gunzip
# ==================================
gzip_gunzip(data_dir, 3, -1)
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
  # Hypothese "Hypo_0vers1"
  # =======================
  Hypo_0vers1 = homard.CreateHypothesis('Hypo_0vers1')
  # Characterization of the field
  Hypo_0vers1.SetField('SOLU_0__QIRE_ELEM_SIGM__________')
  Hypo_0vers1.SetUseComp(0)
  Hypo_0vers1.AddComp('ERREST          ')
  Hypo_0vers1.SetRefinThr(3, 1.0)
  Hypo_0vers1.SetTypeFieldInterp(2)
  Hypo_0vers1.AddFieldInterp('SOLU_0__DEPL____________________')
  Hypo_0vers1.AddFieldInterp('SOLU_0__ERRE_ELEM_SIGM__________')
  #
  # Hypothese "Hypo_1vers2"
  # =======================
  Hypo_1vers2 = homard.CreateHypothesis('Hypo_1vers2')
  # Characterization of the field
  Hypo_1vers2.SetField('SOLU_1__QIRE_ELEM_SIGM__________')
  Hypo_1vers2.SetUseComp(0)
  Hypo_1vers2.AddComp('ERREST          ')
  Hypo_1vers2.SetRefinThr(3, 1.5)
  Hypo_1vers2.SetUnRefThr(3, 6.)
  Hypo_1vers2.SetTypeFieldInterp(2)
  Hypo_1vers2.AddFieldInterp('SOLU_1__DEPL____________________')
  Hypo_1vers2.AddFieldInterp('SOLU_1__QIRE_ELEM_SIGM__________')
  #
  # Hypothese "Hypo_1vers2_bis"
  # ===========================
  Hypo_1vers2_bis = homard.CreateHypothesis('Hypo_1vers2_bis')
  # Characterization of the field
  Hypo_1vers2_bis.SetField('SOLU_1__DEPL____________________')
  Hypo_1vers2_bis.SetUseComp(1)
  Hypo_1vers2_bis.AddComp('DX')
  Hypo_1vers2_bis.AddComp('DY')
  Hypo_1vers2_bis.AddComp('DZ')
  Hypo_1vers2_bis.SetRefinThr(1, 0.0001)
  Hypo_1vers2_bis.SetUnRefThr(1, 0.000001)
  Hypo_1vers2_bis.SetTypeFieldInterp(0)
  #
  # Cas
  # ===
  Case_3 = homard.CreateCase('Case_3', 'G_0', data_dir+'/tutorial_3.00.med')
  Case_3.SetDirName(dircase)
  #
  # Iteration "Iter_3_1"
  # ====================
  Iter_3_1 = Case_3.NextIteration('Iter_3_1')
  Iter_3_1.SetMeshName('H_1')
  Iter_3_1.SetMeshFile(dircase+'/maill.01.med')
  Iter_3_1.SetFieldFile(data_dir+'/tutorial_3.00.med')
  Iter_3_1.SetTimeStepRank( 1, 1)
  Iter_3_1.AssociateHypo('Hypo_0vers1')
  error = Iter_3_1.Compute(1, 2)
  #
  # Iteration "Iter_3_2"
  # ====================
  Iter_3_2 = Iter_3_1.NextIteration('Iter_3_2')
  Iter_3_2.SetMeshName('H_2')
  Iter_3_2.SetMeshFile(dircase+'/maill.02.med')
  Iter_3_2.SetFieldFile(data_dir+'/tutorial_3.01.med')
  Iter_3_2.SetTimeStepRank(1, 1)
  Iter_3_2.AssociateHypo('Hypo_1vers2')
  error = Iter_3_2.Compute(1, 2)
  #
  # Iteration "Iter_3_2_bis"
  # ========================
  Iter_3_2_bis = Iter_3_1.NextIteration('Iter_3_2_bis')
  Iter_3_2_bis.SetMeshName('H_2_bis')
  Iter_3_2_bis.SetMeshFile(dircase+'/maill.02.bis.med')
  Iter_3_2_bis.SetFieldFile(data_dir+'/tutorial_3.01.med')
  Iter_3_2_bis.SetTimeStepRank(1, 1)
  Iter_3_2_bis.AssociateHypo('Hypo_1vers2_bis')
  error = Iter_3_2_bis.Compute(1, 2)
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
n_rep_test_file = 3
test_results(Rep_Test, Test_Name, dircase, n_iter_test_file, n_rep_test_file)
#
# ==================================
gzip_gunzip(data_dir, 3, 1)
# ==================================
#
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
  iparameters.getSession().restoreVisualState(1)

