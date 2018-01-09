# -*- coding: utf-8 -*-
# Copyright (C) 2011-2016  CEA/DEN, EDF R&D
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
Test test_6
"""
__revision__ = "V1.02"

#========================================================================
TEST_NAME = "test_6"
DEBUG = False
N_ITER_TEST_FILE = 3
#
TAILLE = 10.
LG_ARETE = TAILLE*2.5
#========================================================================
import os
import tempfile
import sys
import HOMARD
import salome
#
# ==================================
PATH_HOMARD = os.getenv('HOMARD_ROOT_DIR')
# Repertoire des scripts utilitaires
REP_PYTHON = os.path.join(PATH_HOMARD, "bin", "salome", "test", "HOMARD")
REP_PYTHON = os.path.normpath(REP_PYTHON)
sys.path.append(REP_PYTHON)
from test_util import remove_dir
from test_util import test_results
from test_util import saveGeometry
# Repertoire des donnees du test
REP_DATA = os.path.join(PATH_HOMARD, "share", "salome", "homardsamples")
REP_DATA = os.path.normpath(REP_DATA)
# Repertoire des resultats
if DEBUG :
  DIRCASE = os.path.join("/tmp", TEST_NAME)
  if ( os.path.isdir(DIRCASE) ) :
    remove_dir(DIRCASE)
  os.mkdir(DIRCASE)
else :
  DIRCASE = tempfile.mkdtemp(prefix=TEST_NAME)

salome.salome_init()
import iparameters
IPAR = iparameters.IParameters(salome.myStudy.GetCommonParameters("Interface Applicative", 1))
IPAR.append("AP_MODULES_LIST", "Homard")
#
#========================= Debut de la fonction ==================================
#
def create_geom(nom_obj, taille, verbose=False) :
  """
Création de la géométrie
  """
#
  erreur = 0
#
  if verbose :
    texte = "Geometrie '%s'\n" % nom_obj
    texte += "Taille de base = %f" % taille
    print (texte)
#
  import GEOM
  from salome.geom import geomBuilder
  geompy = geomBuilder.New(salome.myStudy)
#
# 1. Les sommets et la première ligne
#
  vertex_1 = geompy.MakeVertex( 0.*taille,  0.*taille, 0.*taille, theName = "V1")
  vertex_2 = geompy.MakeVertex( 5.*taille,  2.*taille, 0.*taille, theName = "V2")
  vertex_3 = geompy.MakeVertex(10.*taille,  1.*taille, 0.*taille, theName = "V3")
  vertex_4 = geompy.MakeVertex(16.*taille,  4.*taille, 0.*taille, theName = "V4")
  vertex_5 = geompy.MakeVertex(16.*taille, 10.*taille, 0.*taille, theName = "V5")
#
  courbe_0 = geompy.MakeInterpol([vertex_1, vertex_2, vertex_3, vertex_4, vertex_5], False, False, theName="courbe_0")
#
# 2. Les sommets et la seconde ligne
#
  sommet_1 = geompy.MakeVertex( 0.*taille,  0.*taille, 20.*taille, theName = "S1")
  sommet_2 = geompy.MakeVertex( 6.*taille, -5.*taille, 20.*taille, theName = "S2")
  sommet_3 = geompy.MakeVertex(11.*taille, -2.*taille, 20.*taille, theName = "S3")
  sommet_4 = geompy.MakeVertex(12.*taille,  3.*taille, 20.*taille, theName = "S4")
  sommet_5 = geompy.MakeVertex(16.*taille, 10.*taille, 20.*taille, theName = "S5")
#
  courbe_1 = geompy.MakeInterpol([sommet_1, sommet_2, sommet_3, sommet_4, sommet_5], False, False, theName="courbe_1")
#
# 3. La face de base
#
  structure_g = geompy.MakeFilling([courbe_0, courbe_1], theName=nom_obj)
#
# 4. Groupes : on cherche les entites par des proximités avec des shapes bien choisies
#
  l_groupes_g = list()
#
  shape = geompy.GetFaceNearPoint (structure_g, vertex_2)
  nom = "Voile"
  groupe_g = geompy.CreateGroup(structure_g, geompy.ShapeType["FACE"], nom)
  geompy.UnionList ( groupe_g, [shape] )
  l_groupes_g.append( (nom, groupe_g, 2) )
#
  shape = geompy.GetEdgeNearPoint (structure_g, vertex_2)
  nom = "C_0"
  groupe_g = geompy.CreateGroup(structure_g, geompy.ShapeType["EDGE"], nom)
  geompy.UnionList ( groupe_g, [shape] )
  l_groupes_g.append( (nom, groupe_g, 1) )
#
  shape = geompy.GetEdgeNearPoint (structure_g, sommet_2)
  nom = "C_1"
  groupe_g = geompy.CreateGroup(structure_g, geompy.ShapeType["EDGE"], nom)
  geompy.UnionList ( groupe_g, [shape] )
  l_groupes_g.append( (nom, groupe_g, 1) )
#
  shape = geompy.GetEdge (structure_g, vertex_1, sommet_1)
  nom = "D_0"
  groupe_g = geompy.CreateGroup(structure_g, geompy.ShapeType["EDGE"], nom)
  geompy.UnionList ( groupe_g, [shape] )
  l_groupes_g.append( (nom, groupe_g, 1) )
#
  shape = geompy.GetEdge (structure_g, vertex_5, sommet_5)
  nom = "D_1"
  groupe_g = geompy.CreateGroup(structure_g, geompy.ShapeType["EDGE"], nom)
  geompy.UnionList ( groupe_g, [shape] )
  l_groupes_g.append( (nom, groupe_g, 1) )
#
  return erreur, structure_g, l_groupes_g
#
#==========================  Fin de la fonction ==================================
#
#========================= Debut de la fonction ==================================
#
def create_mail(lg_arete, structure_g, l_groupes_g, rep_mail, verbose=False) :
  """
Création du maillage
  """
#
  erreur = 0
  message = ""
  ficmed = ""
#
  while not erreur :
#
    nom = structure_g.GetName()
    if verbose :
      texte = "Maillage de '%s'\n" % nom
      texte += "lg_arete = %f\n" % lg_arete
      texte += "rep_mail = '%s'" % rep_mail
      print (texte)
#
    import SMESH
    from salome.smesh import smeshBuilder
    smesh = smeshBuilder.New(salome.myStudy)
#
# 2. Maillage de calcul
#
    maill_00 = smesh.Mesh(structure_g)
    smesh.SetName(maill_00.GetMesh(), nom)
#
    MG_CADSurf = maill_00.Triangle(algo=smeshBuilder.MG_CADSurf)
    smesh.SetName(MG_CADSurf.GetAlgorithm(), 'MG_CADSurf')
#
    MG_CADSurf_Parameters = MG_CADSurf.Parameters()
    smesh.SetName(MG_CADSurf_Parameters, 'MG_CADSurf Triangles')
    MG_CADSurf_Parameters.SetPhySize( lg_arete )
    MG_CADSurf_Parameters.SetMinSize( lg_arete/20. )
    MG_CADSurf_Parameters.SetMaxSize( lg_arete*5. )
    MG_CADSurf_Parameters.SetChordalError( lg_arete )
    MG_CADSurf_Parameters.SetAngleMesh( 12. )
#
# 3. Les groupes issus de la géométrie
#
    for taux in l_groupes_g :
      groupe_m = maill_00.Group(taux[1])
      smesh.SetName(groupe_m, taux[0])
#
# 4. Calcul
#
    isDone = maill_00.Compute()
    if not isDone :
      message += "Probleme dans le maillage de la surface."
      erreur = 13
      break
#
# 5. Export MED
#
    ficmed = os.path.join(rep_mail,'maill.00.med')
    texte = "Ecriture du fichier '%s'" % ficmed
    if verbose :
      print (texte)
    maill_00.ExportMED( ficmed, 0, SMESH.MED_V2_2, 1 )
#
    break
#
  return erreur, message, ficmed
#
#==========================  Fin de la fonction ==================================
#
#========================= Debut de la fonction ==================================
#
def homard_exec(nom, ficmed, xao_file, verbose=False):
  """
Python script for HOMARD
  """
  erreur = 0
  message = ""
#
  while not erreur :
    #
    HOMARD.SetCurrentStudy(salome.myStudy)
    #
    # Frontière
    # =========
    if verbose :
      print(". Frontière")
    cao_name = "CAO_" + nom
    la_frontiere = HOMARD.CreateBoundaryCAO(cao_name, xao_file)
    #
    # Hypotheses
    # ==========
    if verbose :
      print(". Hypothèses")
    hyponame = "hypo_" + nom
    l_hypothese = HOMARD.CreateHypothesis(hyponame)
    l_hypothese.SetUnifRefinUnRef(1)
    #
    # Cas
    # ===
    if verbose :
      print(". Cas")
    le_cas = HOMARD.CreateCase('case_'+nom, nom, ficmed)
    le_cas.SetDirName(DIRCASE)
    le_cas.AddBoundary(cao_name)
    #
    # Creation of the iterations
    # ==========================
    if verbose :
      option = 2
    else :
      option = 1
    #
    for niter in range(1, N_ITER_TEST_FILE+1):
      if verbose :
        print(". Itération numéro %d" % niter)
      iter_name = "I_" + nom + "_%02d" % niter
      if ( niter == 1 ) :
        l_iteration = le_cas.NextIteration(iter_name)
      else :
        l_iteration = l_iteration.NextIteration(iter_name)
      l_iteration.SetMeshName(nom)
      mesh_file = os.path.join(DIRCASE, "maill.%02d.med" % niter)
      l_iteration.SetMeshFile(mesh_file)
      l_iteration.AssociateHypo(hyponame)
      erreur = l_iteration.Compute(1, option)
      if erreur :
        erreur = niter
        break
    #
    break
  #
  if erreur :
    message += "Erreur au calcul de l'itération %d" % erreur
  #
  return erreur, message
#
#==========================  Fin de la fonction ==================================
#
#
ERREUR = 0
MESSAGE = ""
while not ERREUR :
  #
  VERBOSE = DEBUG
  #
  # A. Geometry
  #
  ERREUR, STRUCTURE_G, L_GROUPES_G = create_geom(TEST_NAME, TAILLE, VERBOSE)
  if ERREUR :
    MESSAGE = "The construction of the geometry failed."
    break
  #
  # B. Save the geometry
  #
  XAO_FILE = os.path.join(DIRCASE, TEST_NAME+".xao")
  try :
    ERREUR = saveGeometry(XAO_FILE, TEST_NAME, "test_salome_"+TEST_NAME)
  except Exception, eee:
    ERREUR = 2000
    MESSAGE = eee.message
  #
  if ERREUR :
    MESSAGE += "Pb in saveGeometry"
    break
  #
  # C. Mesh
  #
  ERREUR, MESSAGE, FICMED = create_mail(LG_ARETE, STRUCTURE_G, L_GROUPES_G, DIRCASE, VERBOSE)
  if ERREUR :
    break
  #
  # D. Exec of HOMARD-SALOME
  #
  HOMARD = salome.lcc.FindOrLoadComponent('FactoryServer', 'HOMARD')
  assert HOMARD is not None, "Impossible to load homard engine"
  HOMARD.SetLanguageShort("fr")
#
  try:
    ERREUR, MESSAGE = homard_exec(TEST_NAME, FICMED, XAO_FILE, VERBOSE)
  except Exception, eee:
    ERREUR = 4000
    MESSAGE = eee.message
  #
  if ERREUR :
    MESSAGE += "Pb in homard_exec"
    break
  #
  # E. Test of the results
  #
  N_REP_TEST_FILE = N_ITER_TEST_FILE
  DESTROY_DIR = not DEBUG
  test_results(REP_DATA, TEST_NAME, DIRCASE, N_ITER_TEST_FILE, N_REP_TEST_FILE, DESTROY_DIR)
  #
  break
#
if ERREUR:
  MESSAGE = "\nErreur numéro %d\n" % ERREUR + MESSAGE
  raise Exception(MESSAGE)
#
if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(True)
  iparameters.getSession().restoreVisualState(1)

