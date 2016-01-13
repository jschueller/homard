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
Test test_2
"""
__revision__ = "V2.5"

#========================================================================
Test_Name = "test_2"
debug=False
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
from test_util import remove_dir
from test_util import test_results
# Repertoire des resultats
if debug :
  dircase = os.path.join("/tmp", Test_Name)
  if ( os.path.isdir(dircase) ) :
    remove_dir(dircase)
  os.mkdir(dircase)
else :
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
  # Creation of the boundaries
  # ==========================
  # Creation of the discrete boundary Boundary_1
    Boundary_1 = homard.CreateBoundaryDi('internal_boundary', 'plaque', os.path.join(Rep_Test, Test_Name + '.fr.med'))
  #
  # Creation of the hypotheses
  # ==========================
  # Creation of the hypothesis 1
    HypoName_1 = "Hypo_" + Test_Name + "_1"
    print "-------- Creation of the hypothesis", HypoName_1
    Hypo_test_2_1 = homard.CreateHypothesis(HypoName_1)
    Hypo_test_2_1.SetUnifRefinUnRef(1)
    Hypo_test_2_1.AddGroup('EG')
    Hypo_test_2_1.AddGroup('BANDE')
    print HypoName_1, " : zones utilisées :", Hypo_test_2_1.GetZones()
    print HypoName_1, " : champ utilisé :", Hypo_test_2_1.GetFieldName()
    print HypoName_1, " : composantes utilisées :", Hypo_test_2_1.GetComps()
    if ( len (Hypo_test_2_1.GetFieldName()) > 0 ) :
      print ".. caractéristiques de l'adaptation :", Hypo_test_2_1.GetField()

  # Creation of the hypothesis 2
    HypoName_2 = "Hypo_" + Test_Name + "_2"
    print "-------- Creation of the hypothesis", HypoName_2
    Hypo_test_2_2 = homard.CreateHypothesis(HypoName_2)
    Hypo_test_2_2.SetUnifRefinUnRef(1)
    Hypo_test_2_2.AddGroup('M_D')
    print HypoName_2, " : zones utilisées :", Hypo_test_2_2.GetZones()
    print HypoName_2, " : champ utilisé :", Hypo_test_2_2.GetFieldName()
    print HypoName_2, " : composantes utilisées :", Hypo_test_2_2.GetComps()
    if ( len (Hypo_test_2_2.GetFieldName()) > 0 ) :
      print ".. caractéristiques de l'adaptation :", Hypo_test_2_2.GetField()
  #
  # Creation of the cases
  # =====================
    # Creation of the case
    CaseName = "Case_" + Test_Name
    MeshFile = os.path.join(Rep_Test, Test_Name + '.00.med')
    Case_test_2 = homard.CreateCase(CaseName, 'PLAQUE_0', MeshFile)
    Case_test_2.SetDirName(dircase)
    Case_test_2.AddBoundaryGroup('internal_boundary', '')
  #
  # Creation of the iterations
  # ==========================
  # Creation of the iteration 1
    IterName = "I_" + Test_Name + "_1"
    Iter_test_2_1 = Case_test_2.NextIteration(IterName)
    Iter_test_2_1.SetMeshName('PLAQUE_1')
    Iter_test_2_1.SetMeshFile(os.path.join(dircase, 'maill.01.med'))
    Iter_test_2_1.AssociateHypo(HypoName_1)
    error = Iter_test_2_1.Compute(1, 1)
    if error :
      error = 1
      break

  # Creation of the iteration 2
    IterName = "I_" + Test_Name + "_2"
    Iter_test_2_2 = Iter_test_2_1.NextIteration(IterName)
    Iter_test_2_2.SetMeshName('PLAQUE_2')
    Iter_test_2_2.SetMeshFile(os.path.join(dircase, 'maill.02.med'))
    Iter_test_2_2.AssociateHypo(HypoName_1)
    error = Iter_test_2_2.Compute(1, 1)
    if error :
      error = 2
      break

  # Creation of the iteration 3
    IterName = "I_" + Test_Name + "_3"
    Iter_test_2_3 = Iter_test_2_2.NextIteration(IterName)
    Iter_test_2_3.SetMeshName('PLAQUE_3')
    Iter_test_2_3.SetMeshFile(os.path.join(dircase, 'maill.03.med'))
    Iter_test_2_3.AssociateHypo(HypoName_2)
    error = Iter_test_2_3.Compute(1, 1)
    if error :
      error = 3
      break
  #
  # Creation of the schema YACS
  # ===========================
    ScriptFile = os.path.join(pathHomard, "share", "doc", "salome", "gui", "HOMARD", "en", "_downloads", "yacs_script_test.py")
    ScriptFile = os.path.normpath(ScriptFile)
    DirName = dircase
    YACS_test_2 = Case_test_2.CreateYACSSchema("YACS_test_2", ScriptFile, DirName, MeshFile)
    YACS_test_2.SetMaxIter(4)
    YACS_test_2.SetType(1)
    filexml = os.path.join(dircase, 'YACS_test_2.xml')
    error = YACS_test_2.WriteOnFile(filexml)
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
destroy_dir = not debug
test_results(Rep_Test, Test_Name, dircase, n_iter_test_file, n_rep_test_file, destroy_dir)
#
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
  iparameters.getSession().restoreVisualState(1)

