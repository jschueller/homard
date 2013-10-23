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
Copyright EDF-R&D 2011, 2013
Test test_3
"""
__revision__ = "V1.12"

#========================================================================
Test_Name = "test_3"
n_boucle = 2
n_iter_test_file = 2
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
# Creation of the discrete boundary
    Boundary_3_1 = homard.CreateBoundaryDi('courbes', 'COURBES', os.path.join(Rep_Test, Test_Name + '.fr.med'))
#
# Creation of the external cylinder
    Boundary_3_2 = homard.CreateBoundaryCylinder('cyl_ext', 50.0, 25., -25., 1., 0., 0., 100.)
#
# Creation of the internal cylinder
    Boundary_3_3 = homard.CreateBoundaryCylinder('cyl_int', 50.0, 25., -25., 1., 0., 0., 50.)
#
# Creation of the first sphere
    Boundary_3_4 = homard.CreateBoundarySphere('sphere_1', 50.0, 25., -25., 100.)
#
# Creation of the second sphere
    Boundary_3_5 = homard.CreateBoundarySphere('sphere_2', 450.0, 25., -25., 100.)
#
# Creation of the hypotheses
# ==========================
# Uniform refinement
    HypoName = "Hypo_" + Test_Name
    print "-------- Creation of the hypothesis", HypoName
    Hypo_test_3 = homard.CreateHypothesis(HypoName)
    Hypo_test_3.SetAdapRefinUnRef(-1, 1, 0)
    print HypoName, " : zones utilisées :", Hypo_test_3.GetZones()
    print HypoName, " : champ utilisé :", Hypo_test_3.GetFieldName()
    print HypoName, " : composantes utilisées :", Hypo_test_3.GetComps()
#
    for num in range (n_boucle+1) :
#
      print "-------- num =", num, "--------"
#
# Creation of the case Case_test_3
# ===========================
      if ( num <= 1 ) :
        CaseName = "Case_" + Test_Name
        print "-------- Creation of the case", CaseName
        MeshFile = os.path.join(Rep_Test, Test_Name + '.00.med')
        Case_test_3 = homard.CreateCase(CaseName, 'MOYEU', MeshFile)
        Case_test_3.SetDirName(Rep_Test_Resu)
        Case_test_3.SetConfType(1)
        Case_test_3.AddBoundaryGroup('courbes', '')
        Case_test_3.AddBoundaryGroup('cyl_ext', 'EXT')
        Case_test_3.AddBoundaryGroup('cyl_int', 'INT')
        Case_test_3.AddBoundaryGroup('sphere_1', 'END_1')
        Case_test_3.AddBoundaryGroup('sphere_2', 'END_2')
#
# Creation of the iterations
# ==========================
  # Creation of the iteration  1
      IterName = "I_" + Test_Name + "_1"
      print "-------- Creation of the iteration", IterName
      Iter_test_3_1 = Case_test_3.NextIteration(IterName)
      Iter_test_3_1.SetMeshName('MOYEU_1')
      Iter_test_3_1.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.01.med'))
      Iter_test_3_1.AssociateHypo('Hypo_test_3')
      error = Iter_test_3_1.Compute(1, 1)
      if error :
        error = 10*num + 1
        break

  # Creation of the iteration 2
      IterName = "I_" + Test_Name + "_2"
      print "-------- Creation of the iteration", IterName
      Iter_test_3_2 = Iter_test_3_1.NextIteration(IterName)
      Iter_test_3_2.SetMeshName('MOYEU_2')
      Iter_test_3_2.SetMeshFile(os.path.join(Rep_Test_Resu, 'maill.02.med'))
      Iter_test_3_2.AssociateHypo('Hypo_test_3')
      error = Iter_test_3_2.Compute(1, 1)
      if error :
        error = 10*num + 2
        break
  #
  # Creation of the schema YACS
  # ===========================
      ScriptFile = os.path.join(pathHomard, "share", "doc", "salome", "gui", "HOMARD", "en", "_downloads", "yacs_script.py")
      ScriptFile = os.path.normpath(ScriptFile)
      DirName = Rep_Test_Resu
      YACSName = "YACS_" + Test_Name
      print "-------- Creation of the schema", YACSName
      YACS_test_3 = Case_test_3.CreateYACSSchema(YACSName, ScriptFile, DirName, MeshFile)
      YACS_test_3.SetType(2)
      error = YACS_test_3.Write()
      if error :
        error = 10*num + 5
        break

  # Destructions
  # ============
  # Destruction of the schema, sauf a la fin
      if ( num < n_boucle ) :
        print "-------- Destruction of the schema", YACS_test_3.GetName()
        error = YACS_test_3.Delete(1)
        if error :
          error = 10*num + 6
          break
  # After the first loop, the case is deleted, except the final mesh files
  # All the iterations are deleted
      if ( num == 0 ) :
        print "-------- Destruction of the case", Case_test_3.GetName()
        error = Case_test_3.Delete(0)
        if error :
          break
  # After the second loop, the iterations are deleted, with the final mesh files
      elif ( num == 1 ) :
  # Recursive destruction of the iterations
        print "-------- Recursive destruction of the iteration", Iter_test_3_1.GetName()
        error = Iter_test_3_1.Delete(1)
        if error :
          error = 10*num + 3
          break
  # Destruction and creation of the hypothese
        if ( num == 1 ) :
          print "-------- Destruction of the hypothese", Hypo_test_3.GetName()
          error = Hypo_test_3.Delete()
          if error :
            error = 10*num + 4
            break
          HypoName = "Hypo_test_3"
          print "-------- Creation of the hypothesis", HypoName
          Hypo_test_3 = homard.CreateHypothesis(HypoName)
          Hypo_test_3.SetAdapRefinUnRef(-1, 1, 0)
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
rep_test_file = "I%02d" % (n_iter_test_file*n_boucle)
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

