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
Test test_4
"""
__revision__ = "V1.0"

#========================================================================
Test_Name = "test_4"
debug=False
n_iter_test_file = 3
DX = 600.
DY = 400.
DZ = 200.
#========================================================================
import os
import tempfile
import sys
import numpy as np
import salome
import GEOM
import SMESH
import HOMARD
import MEDCoupling as mc
import MEDLoader as ml
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

import SALOMEDS
from salome.geom import geomBuilder
from salome.smesh import smeshBuilder
from salome.StdMeshers import StdMeshersBuilder
#
from MEDLoader import MEDLoader
from MEDCouplingRemapper import MEDCouplingRemapper

import iparameters
ipar = iparameters.IParameters(salome.myStudy.GetCommonParameters("Interface Applicative", 1))
ipar.append("AP_MODULES_LIST", "Homard")
#
#========================================================================
#========================================================================
def geom_smesh_exec(theStudy):
  """
Python script for GEOM and SMESH
  """
  error = 0
#
  while not error :
  #
    geompy = geomBuilder.New(theStudy)
  #
  # Creation of the box
  # ===================
    BOX = geompy.MakeBoxDXDYDZ(DX, DY, DZ, "BOX")

  # Creation of the mesh
  # ====================
    smesh = smeshBuilder.New(theStudy)
    MESH = smesh.Mesh(BOX)
    smesh.SetName(MESH.GetMesh(), 'MESH')
  #
  # Creation of the hypotheses
  # ==========================
    Regular_1D = MESH.Segment()
    smesh.SetName(Regular_1D.GetAlgorithm(), 'Regular_1D')
    Length = min(DX, DY, DZ) / 5.
    Local_Length = Regular_1D.LocalLength(Length,None,1e-07)
    smesh.SetName(Local_Length, 'Local Length')
  #
    Quadrangle_2D = MESH.Quadrangle(algo=smeshBuilder.QUADRANGLE)
    smesh.SetName(Quadrangle_2D.GetAlgorithm(), 'Quadrangle_2D')
    Quadrangle_Parameters = Quadrangle_2D.QuadrangleParameters(StdMeshersBuilder.QUAD_STANDARD,-1,[],[])
    smesh.SetName(Quadrangle_Parameters, 'Quadrangle Parameters')
  #
    Hexa_3D = MESH.Hexahedron(algo=smeshBuilder.Hexa)
    smesh.SetName(Hexa_3D.GetAlgorithm(), 'Hexa_3D')
  #
  # Computation
  # ===========
  #
    isDone = MESH.Compute()
    if not isDone :
      error = 1
      break
  #
  # MED exportation
  # ===============
  #
    try:
      ficmed = os.path.join(dircase, 'maill.00.med')
      MESH.ExportMED( ficmed, 0, SMESH.MED_V2_2, 1, None ,1)
    except Exception, e:
      raise Exception('ExportToMEDX() failed. '+e.message)
      error = 2
  #
    break
  #
  return error

#========================================================================
#
#========================================================================
def field_exec(theStudy, niter):
  """
Python script for MEDCoupling
  """
  error = 0
#
  while not error :
  #
  # The mesh
  # ========
    ficmed = os.path.join(dircase, 'maill.%02d.med' % niter)
    meshMEDFileRead = ml.MEDFileMesh.New(ficmed)
    meshRead0 = meshMEDFileRead.getMeshAtLevel(0)
  # Valeurs of the field
  # ====================
    nbNodes = meshRead0.getNumberOfNodes()
    valeur = mc.DataArrayDouble(nbNodes)
    for iaux, taux in enumerate(meshRead0.getCoords()) :
      #ligne   = "x = %f" % taux[0]
      #ligne  += ", y = %f" % taux[1]
      #ligne  += ", z = %f" % taux[2]
      #print ligne
      #distance = (taux[0]-DX*0.2)**2 + (taux[1]-DY*0.2)**2 + (taux[2]-DZ*0.4)**2
      distance = min(abs(taux[0]-DX*0.4), abs(taux[1]-DY*0.2), abs(taux[2]-DZ*0.4))
      valeur[iaux] = 1.e0 / max ( 1.e-5, np.sqrt(distance) )
    #print ". valeur", valeur
    nparr = valeur.toNumPyArray()
    print ". mini/maxi", nparr.min(), nparr.max()
  #
  # Creation of the field
  # =====================
    field = ml.MEDCouplingFieldDouble(ml.ON_NODES, ml.ONE_TIME)
    field.setArray(valeur)
    field.setMesh(meshRead0)
    field.setName("DISTANCE")
  #
    fMEDFile_ch = ml.MEDFileField1TS()
    fMEDFile_ch.setFieldNoProfileSBT(field)     # No profile desired on the field, Sort By Type
    fMEDFile_ch.write(ficmed, 0) # 0 to indicate that we *append* (and no overwrite) to the MED file
  #
    break
  #
  return error

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
  #
    epsilon = min(DX, DY, DZ) / 100.
  # Creation of the box Zone_4_1
    Zone_4_1 = homard.CreateZoneBox('Zone_4_1', -epsilon, DX/3.+epsilon, DY/4.-epsilon, 3.*DY/4.+epsilon, 4.*DZ/5.-epsilon, DZ+epsilon)

  # Creation of the sphere Zone_4_2
    rayon = min(DX, DY, DZ) / 4.
    Zone_4_2 = homard.CreateZoneSphere('Zone_4_2', DX/3., DY*0.3, DZ*0.6, rayon)
  #
  # Creation of the hypotheses
  # ==========================
    dico = {}
    dico["1"] = "raffinement"
    dico["-1"] = "deraffinement"
  # Creation of the hypothesis Hypo_4_1
    HypoName_1 = "Zone_1"
    print "-------- Creation of the hypothesis", HypoName_1
    Hypo_4_1 = homard.CreateHypothesis(HypoName_1)
    Hypo_4_1.AddZone('Zone_4_1', 1)
    Hypo_4_1.SetExtraOutput(2)
    laux = Hypo_4_1.GetZones()
    nbzone = len(laux)/2
    jaux = 0
    for iaux in range(nbzone) :
      print HypoName_1, " : ", dico[laux[jaux+1]], "sur la zone", laux[jaux]
      jaux += 2
  # Creation of the hypothesis Hypo_4_2
    HypoName_2 = "Zone_2"
    print "-------- Creation of the hypothesis", HypoName_2
    Hypo_4_2 = homard.CreateHypothesis(HypoName_2)
    Hypo_4_2.AddZone('Zone_4_2', 1)
    Hypo_4_2.SetExtraOutput(2)
    laux = Hypo_4_2.GetZones()
    nbzone = len(laux)/2
    jaux = 0
    for iaux in range(nbzone) :
      print HypoName_2, " : ", dico[laux[jaux+1]], "sur la zone", laux[jaux]
      jaux += 2
  # Creation of the hypothesis DISTANCE INVERSE
    HypoName_3 = "DISTANCE INVERSE"
    print "-------- Creation of the hypothesis", HypoName_3
    Hypo_4_3 = homard.CreateHypothesis(HypoName_3)
    Hypo_4_3.SetField('DISTANCE')
    Hypo_4_3.SetUseComp(0)
    Hypo_4_3.SetRefinThr(1, 0.3)
    Hypo_4_3.SetUnRefThr(1, 0.2)
    Hypo_4_3.AddFieldInterp('DISTANCE')
    Hypo_4_3.SetExtraOutput(2)
    print HypoName_3, " : zones utilisées :", Hypo_4_3.GetZones()
    print HypoName_3, " : champ utilisé :", Hypo_4_3.GetFieldName()
    print HypoName_3, " : composantes utilisées :", Hypo_4_3.GetComps()
    if ( len (Hypo_4_3.GetFieldName()) > 0 ) :
      print ".. caractéristiques de l'adaptation :", Hypo_4_3.GetField()
    print HypoName_3, " : champs interpolés :", Hypo_4_3.GetFieldInterps()
  #
  # Creation of the cases
  # =====================
    # Creation of the case
    CaseName = "Case_" + Test_Name
    print "-------- Creation of the case", CaseName
    MeshFile = os.path.join(dircase, 'maill.00.med')
    Case_test_4 = homard.CreateCase(CaseName, 'MESH', MeshFile)
    Case_test_4.SetDirName(dircase)
  #
  # Creation of the iterations
  # ==========================
  # Creation of the iteration 1
    IterName = "I_" + Test_Name + "_1"
    print "-------- Creation of the iteration", IterName
    Iter_test_4_1 = Case_test_4.NextIteration(IterName)
    Iter_test_4_1.AssociateHypo(HypoName_1)
    print ". Hypothese :", HypoName_1
    Iter_test_4_1.SetMeshName('M1')
    Iter_test_4_1.SetMeshFile(os.path.join(dircase, 'maill.01.med'))
    error = Iter_test_4_1.Compute(1, 2)
    if error :
      error = 1
      break

  # Creation of the iteration 2
    IterName = "I_" + Test_Name + "_2"
    print "-------- Creation of the iteration", IterName
    Iter_test_4_2 = Iter_test_4_1.NextIteration(IterName)
    Iter_test_4_2.AssociateHypo(HypoName_2)
    print ". Hypothese :", HypoName_2
    Iter_test_4_2.SetMeshName('M2')
    Iter_test_4_2.SetMeshFile(os.path.join(dircase, 'maill.02.med'))
    error = Iter_test_4_2.Compute(1, 2)
    if error :
      error = 2
      break

  # Creation of the iteration 3
  #
    error = field_exec(theStudy, 2)
    if error :
      error = 30
      break
  #
    IterName = "I_" + Test_Name + "_3"
    print "-------- Creation of the iteration", IterName
    Iter_test_4_3 = Iter_test_4_2.NextIteration(IterName)
    Iter_test_4_3.AssociateHypo(HypoName_3)
    print ". Hypothese :", HypoName_3
    Iter_test_4_3.SetMeshName('M3')
    Iter_test_4_3.SetFieldFile(os.path.join(dircase, 'maill.02.med'))
    Iter_test_4_3.SetMeshFile(os.path.join(dircase, 'maill.03.med'))
    error = Iter_test_4_3.Compute(1, 2)
    if error :
      error = 3
      break
  #
    break
  #
  return error

#========================================================================
#
# Geometry and Mesh
#
try :
  error_main = geom_smesh_exec(salome.myStudy)
  if error_main :
    raise Exception('Pb in geom_smesh_exec')
except Exception, e:
  raise Exception('Pb in geom_smesh_exec: '+e.message)

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

