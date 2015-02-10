# -*- coding: utf-8 -*-
# Copyright (C) 2011-2015  CEA/DEN, EDF R&D
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
Test test_1
"""
__revision__ = "V2.4"

#========================================================================
Test_Name = "test_1"
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
  error = 0
#
  while not error :
  #
    homard.SetCurrentStudy(theStudy)
  #
  # Creation of the zones
  # =====================
  # Creation of the box Zone_1_1
    Zone_1_1 = homard.CreateZoneBox('Zone_1_1', -0.01, 1.01, -0.01, 0.4, -0.01, 0.6)

  # Creation of the sphere Zone_1_2
    Zone_1_2 = homard.CreateZoneSphere('Zone_1_2', 0.5, 0.6, 0.7, 0.75)
  #
  # Creation of the hypotheses
  # ==========================
  # Creation of the hypothesis a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM
    HypoName_1 = "a10_1pc_de_mailles_a_raffiner_sur_ERRE_ELEM_SIGM"
    print "-------- Creation of the hypothesis", HypoName_1
    Hypo_1_1 = homard.CreateHypothesis(HypoName_1)
    Hypo_1_1.SetField('RESU____ERRE_ELEM_SIGM__________')
    Hypo_1_1.SetUseComp(0)
    Hypo_1_1.AddComp('ERREST')
    Hypo_1_1.SetRefinThr(3, 10.1)
    Hypo_1_1.AddFieldInterp('RESU____DEPL____________________')
    Hypo_1_1.AddFieldInterp('RESU____ERRE_ELEM_SIGM__________')
    print HypoName_1, " : zones utilisées :", Hypo_1_1.GetZones()
    print HypoName_1, " : champ utilisé :", Hypo_1_1.GetFieldName()
    print HypoName_1, " : composantes utilisées :", Hypo_1_1.GetComps()
    if ( len (Hypo_1_1.GetFieldName()) > 0 ) :
      print ".. caractéristiques de l'adaptation :", Hypo_1_1.GetField()
    print HypoName_1, " : champs interpolés :", Hypo_1_1.GetFieldInterps()
  # Creation of the hypothesis Zones_1_et_2
    HypoName_2 = "Zones_1_et_2"
    print "-------- Creation of the hypothesis", HypoName_2
    Zones_1_et_2 = homard.CreateHypothesis(HypoName_2)
    Zones_1_et_2.AddZone('Zone_1_1', 1)
    Zones_1_et_2.AddZone('Zone_1_2', 1)
    print HypoName_2, " : zones utilisées :", Zones_1_et_2.GetZones()
    print HypoName_2, " : champ utilisé :", Zones_1_et_2.GetFieldName()
    if ( len (Zones_1_et_2.GetFieldName()) > 0 ) :
      print ".. caractéristiques de l'adaptation :", Zones_1_et_2.GetField()
    print HypoName_2, " : champs interpolés :", Zones_1_et_2.GetFieldInterps()
  #
  # Creation of the cases
  # =====================
    # Creation of the case
    CaseName = "Case_" + Test_Name
    print "-------- Creation of the case", CaseName
    MeshFile = os.path.join(Rep_Test, Test_Name + '.00.med')
    Case_test_1 = homard.CreateCase(CaseName, 'MAILL', MeshFile)
    Case_test_1.SetDirName(dircase)
    Case_test_1.SetConfType(1)
  #
  # Creation of the iterations
  # ==========================
  # Creation of the iteration 1
    IterName = "I_" + Test_Name + "_1"
    print "-------- Creation of the iteration", IterName
    Iter_test_1_1 = Case_test_1.NextIteration(IterName)
    Iter_test_1_1.AssociateHypo(HypoName_1)
    print ". Hypothese :", HypoName_1
    Iter_test_1_1.SetMeshName('M1')
    Iter_test_1_1.SetMeshFile(os.path.join(dircase, 'maill.01.med'))
    Iter_test_1_1.SetFieldFile(os.path.join(Rep_Test, Test_Name + '.00.med'))
    Iter_test_1_1.SetTimeStepRank(1, 1)
    Iter_test_1_1.SetFieldInterpTimeStep('RESU____DEPL____________________', 1)
    Iter_test_1_1.SetFieldInterpTimeStepRank('RESU____ERRE_ELEM_SIGM__________', 1, 1)
    print ". Instants d'interpolation :", Iter_test_1_1.GetFieldInterpsTimeStepRank()
    error = Iter_test_1_1.Compute(1, 1)
    if error :
      error = 1
      break

  # Creation of the iteration 2
    IterName = "I_" + Test_Name + "_2"
    print "-------- Creation of the iteration", IterName
    Iter_test_1_2 = Iter_test_1_1.NextIteration(IterName)
    Iter_test_1_2.AssociateHypo(HypoName_1)
    print ". Hypothese :", HypoName_1
    Iter_test_1_2.SetMeshName('M2')
    Iter_test_1_2.SetMeshFile(os.path.join(dircase, 'maill.02.med'))
    Iter_test_1_2.SetFieldFile(os.path.join(Rep_Test, Test_Name + '.01.med'))
    Iter_test_1_2.SetTimeStepRank(1, 1)
    Iter_test_1_2.SetFieldInterpTimeStep('RESU____DEPL____________________', 1)
    Iter_test_1_2.SetFieldInterpTimeStepRank('RESU____ERRE_ELEM_SIGM__________', 1, 1)
    print ". Instants d'interpolation :", Iter_test_1_2.GetFieldInterpsTimeStepRank()
    error = Iter_test_1_2.Compute(1, 1)
    if error :
      error = 2
      break

  # Creation of the iteration 3
    IterName = "I_" + Test_Name + "_3"
    print "-------- Creation of the iteration", IterName
    Iter_test_1_3 = Iter_test_1_2.NextIteration(IterName)
    Iter_test_1_3.AssociateHypo(HypoName_2)
    print ". Hypothese :", HypoName_2
    Iter_test_1_3.SetMeshName('M3')
    Iter_test_1_3.SetMeshFile(os.path.join(dircase, 'maill.03.med'))
    Iter_test_1_2.SetFieldFile(os.path.join(Rep_Test, Test_Name + '.02.med'))
    print ". Instants d'interpolation :", Iter_test_1_3.GetFieldInterpsTimeStepRank()
    error = Iter_test_1_3.Compute(1, 1)
    if error :
      error = 3
      break
  #
  # Creation of the schema YACS
  # ===========================
    ScriptFile = os.path.join(pathHomard, "share", "doc", "salome", "gui", "HOMARD", "en", "_downloads", "yacs_script_test.py")
    ScriptFile = os.path.normpath(ScriptFile)
    DirName = dircase
    YACS_test_1 = Case_test_1.CreateYACSSchema("YACS_test_1", ScriptFile, DirName, MeshFile)
    error = YACS_test_1.Write()
    if error :
      error = 4
      break
  #
    break
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
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
  iparameters.getSession().restoreVisualState(1)

