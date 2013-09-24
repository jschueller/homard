# -*- coding: iso-8859-1 -*-
# Copyright (C) 2011-2013  CEA/DEN, EDF R&D
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License.
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
Copyright EDF-R&D 2010, 2013
Test test_2
"""
__revision__ = "V1.10"

#========================================================================
Test_Name = "test_2"
n_iter_test_file = 3
#========================================================================
import os
import tempfile
import HOMARD
import salome
#
pathHomard = os.getenv('HOMARD_ROOT_DIR')
Rep_Test = os.path.join(pathHomard, "share", "salome", "resources", "homard")
Rep_Test = os.path.normpath(Rep_Test)
Rep_Test_Resu = tempfile.mktemp()
os.mkdir(Rep_Test_Resu)

salome.salome_init()
import iparameters
ipar = iparameters.IParameters(salome.myStudy.GetCommonParameters("Interface Applicative", 1))
ipar.append("AP_MODULES_LIST", "Homard")
#========================================================================
#========================================================================
def remove_dir(directory) :
  """
Empties, then removes a directory.
Copyright EDF-R&D 2013
  """
#
  l_aux = os.listdir(directory)
  for fic in l_aux :
    fic_a = os.path.join(directory, fic)
    if os.path.isdir(fic_a) :
      remove_dir(fic_a)
    else :
      os.remove(fic_a)
  os.rmdir(directory)
#
  return
#
#========================================================================
#========================================================================
def homard_exec(theStudy):
  """
Python script for HOMARD
Copyright EDF-R&D 2010, 2013
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
  # Creation of the hypothesis Hypo_2_1
    Hypo_2_1 = homard.CreateHypothesis('Hypo_2_1')
    Hypo_2_1.SetAdapRefinUnRef(-1, 1, 0)
    Hypo_2_1.AddGroup('EG')
    Hypo_2_1.AddGroup('BANDE')

  # Creation of the hypothesis Hypo_2_2
    Hypo_2_2 = homard.CreateHypothesis('Hypo_2_2')
    Hypo_2_2.SetAdapRefinUnRef(-1, 1, 0)
    Hypo_2_2.AddGroup('M_D')
  #
  # Creation of the cases
  # =====================
    # Creation of the case Case_2
    MeshFile = os.path.join(Rep_Test, Test_Name + '.00.med')
    Case_2 = homard.CreateCase('Case_2', 'PLAQUE_0', MeshFile)
    Case_2.SetDirName(Rep_Test_Resu)
    Case_2.SetConfType(1)
    Case_2.AddBoundaryGroup('internal_boundary', '')
  #
  # Creation of the iterations
  # ==========================
  # Creation of the iteration Iter_2_1
    Iter_2_1 = Case_2.NextIteration('Iter_2_1')
    Iter_2_1.SetMeshName('PLAQUE_1')
    Iter_2_1.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.01.med'))
    Iter_2_1.AssociateHypo('Hypo_2_1')
    error = Iter_2_1.Compute(1, 1)
    if error :
      error = 1
      break

  # Creation of the iteration Iter_2_2
    Iter_2_2 = Iter_2_1.NextIteration('Iter_2_2')
    Iter_2_2.SetMeshName('PLAQUE_2')
    Iter_2_2.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.02.med'))
    Iter_2_2.AssociateHypo('Hypo_2_1')
    error = Iter_2_2.Compute(1, 1)
    if error :
      error = 2
      break

  # Creation of the iteration Iter_2_3
    Iter_2_3 = Iter_2_2.NextIteration('Iter_2_3')
    Iter_2_3.SetMeshName('PLAQUE_3')
    Iter_2_3.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.03.med'))
    Iter_2_3.AssociateHypo('Hypo_2_2')
    error = Iter_2_3.Compute(1, 1)
    if error :
      error = 3
      break
  #
  # Creation of the schema YACS
  # ===========================
    ScriptFile = os.path.join(pathHomard, "share", "doc", "salome", "gui", "HOMARD", "en", "_downloads", "yacs_script.py")
    ScriptFile = os.path.normpath(ScriptFile)
    DirName = Rep_Test_Resu
    YACS_2 = Case_2.CreateYACSSchema("YACS_2", ScriptFile, DirName, MeshFile)
    filexml = os.path.join(Rep_Test_Resu, 'YACS_2.xml')
    error = YACS_2.WriteOnFile(filexml)
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
# Test of the result
#
test_file_suff = "apad.%02d.bilan" % n_iter_test_file
rep_test_file = "I%02d" % n_iter_test_file
#
test_file = os.path.join(Rep_Test, Test_Name + "." + test_file_suff)
mess_error_ref = "\nReference file: " + test_file
try :
  file = open (test_file, "r")
  mess_ref = file.readlines()
  file.close()
except :
  mess_error = mess_error_ref + "\nThis file does not exist.\n"
  raise Exception(mess_error)
#
test_file = os.path.join(Rep_Test_Resu, rep_test_file, test_file_suff)
if os.path.isfile (test_file) :
  file = open (test_file, "r")
  mess = file.readlines()
  file.close()
else :
  mess_error  = "\nResult file: " + test_file
  mess_error += "\nThis file does not exist.\n"
  raise Exception(mess_error)

nblign = len(mess_ref)
if ( len(mess) != nblign ):
  mess_error = mess_error_ref +  "\nResult file: " + test_file
  mess_error += "\nThe number of lines of the files are not the same.\n"
  raise Exception(mess_error)

for num in range(nblign) :
  if (( "creation" not in mess_ref[num] ) and ( mess_ref[num] != mess[num])) :
    message_erreur = "\nRefe : " + mess_ref[num]
    message_erreur += "Test : " + mess[num][:-1]
    message_erreur += "\nThe test is different from the reference."
    raise Exception(message_erreur)
#
remove_dir(Rep_Test_Resu)
#
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
  iparameters.getSession().restoreVisualState(1)

