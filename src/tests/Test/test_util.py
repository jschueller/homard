# -*- coding: utf-8 -*-
# Copyright (C) 2011-2017  CEA/DEN, EDF R&D
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
Utilitaires pour les tests
"""
__revision__ = "V3.01"

import os
import MEDLoader as ml
import shutil
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
def test_results(rep_test, test_name, dircase, n_iter_test_file, n_rep_test_file, destroy_dir = True) :
  """
Test of the result
rep_test: repertoire des tests
test_name: nom du test
dircase: repertoire des resultats du test
n_iter_test_file: numero de l'iteration a tester
n_rep_test_file: numero du repertoire de l'iteration a tester
destroy_dir: destruction du repertoire de calcul
Copyright EDF-R&D 2014
  """
  #
  test_file_suff = "apad.%02d.bilan" % n_iter_test_file
  rep_test_file = "I%02d" % n_rep_test_file
  #
  test_file = os.path.join(rep_test, test_name + "." + test_file_suff)
  mess_error_ref = "\nReference file: " + test_file
#
# Existence du fichier de référence
#
  try :
    file = open (test_file, "r")
    les_lignes_ref = file.readlines()
    file.close()
  except :
    mess_error = mess_error_ref + "\nThis file does not exist.\n"
    destroy_dir = False
    raise Exception(mess_error)
#
# Existence du fichier de l'exécution courante
#
  test_file = os.path.join(dircase, rep_test_file, test_file_suff)
  if os.path.isfile (test_file) :
    file = open (test_file, "r")
    les_lignes = file.readlines()
    file.close()
  else :
    mess_error  = "\nResult file: " + test_file
    mess_error += "\nThis file does not exist.\n"
    destroy_dir = False
    raise Exception(mess_error)
#
# Nombre de lignes identiques
#
  nblign = len(les_lignes_ref)
  if ( len(les_lignes) != nblign ):
    mess_error = mess_error_ref +  "\nResult file: " + test_file
    mess_error += "\nThe number of lines of the files are not the same.\n"
    destroy_dir = False
    raise Exception(mess_error)
#
# Comparaison des lignes, à l'esception de la date
#
  for num in range(nblign) :
    if ( "creation" not in les_lignes_ref[num] ) :
      if ( les_lignes_ref[num] != les_lignes[num] ) :
        message_erreur = "\nRefe : " + les_lignes_ref[num]
        message_erreur += "Test : " + les_lignes[num][:-1]
        message_erreur += "\nThe test is different from the reference."
        destroy_dir = False
        raise Exception(message_erreur)
#
# Destruction éventuelle du répertoire du calcul
#
  if destroy_dir:
    remove_dir(dircase)
#
  return
#
#========================================================================
#========================================================================
#
def saveGeometry( xao_file, name, author="" ):
  """
  Save the geometry in a XAO file
  """
  import salome
  from salome.geom import geomBuilder
  geompy = geomBuilder.New(salome.myStudy)
  error = 0

  # find an object having groups in GEOM component
  component = salome.myStudy.FindObjectByPath("/Geometry")
  it = salome.myStudy.NewChildIterator( component )
  geomObj = None
  l_groups = list()
  while it.More():
    so = it.Value()
    it.Next()
    go = so.GetObject()
    #
    if go:
      if ( go.GetName() == name ) :
        subIt = salome.myStudy.NewChildIterator( so )
        while subIt.More():
          subSO = subIt.Value()
          subIt.Next()
          if not subSO.GetName(): continue # a reference
          gr = subSO.GetObject()
          if gr and geompy.ShapeIdToType( gr.GetType() ) == "GROUP":
            l_groups.append( gr )
        geomObj = go
        break

  if not geomObj:
    raise RuntimeError("Cant find a geometry object in the SALOME study with name = '%s'" % name)

  # save the geom object in a XAO file
  l_fields = list()
  ok = geompy.ExportXAO( geomObj, l_groups, l_fields, author, xao_file, "" )
  error = not ok

  return error
#
#========================================================================
#========================================================================
#
def repositionnement (rep_calc, fic_med_brut, fic_med_new, xao_file, verbose=False) :
#
  """
Pilote le repositionnement des noeuds qui ont bougé
Entrées :
  rep_calc : répertoire du calcul HOMARD qui est à traiter
  fic_med_brut : fichier MED du calcul avec les coordonnées avant projection
  fic_med_new  : fichier MED du calcul avec les coordonnées après projection
  xao_file : fichier XAO de la géométrie
  """
  if verbose :
    ligne =    "rep_calc     = %s" % rep_calc
    ligne += "\nfic_med_brut = %s" % fic_med_brut
    ligne += "\nfic_med_new  = %s" % fic_med_new
    ligne += "\nxao_file     = %s" % xao_file
    print(ligne)

  message = ""
  erreur = 0
  while not erreur :
#
# 1. l_fr = liste des fichiers des lignes/surfaces a suivre
#           Les fichiers des numéros de groupes par frontière sont renommés selon le support
#           à condition de ne pas être vide.
#
    fic_hom_med = None
    laux = os.listdir(rep_calc)
    #print laux
    l_fr = list()
    icpt_1D = 0
    icpt_2D = 0
    for fic in laux :
      #print "\t" + fic
      if ( fic[:5] == 'fort.' ) :
        fic_fort = os.path.join(rep_calc, fic)
        fichier = open (fic_fort, "r")
        les_lignes = fichier.readlines()
        fichier.close()
        os.remove(fic_fort)
        a_faire = False
        for ligne in les_lignes[1:] :
          laux1 = ligne.split()
          if ( len(laux1) >= 3 ) :
            a_faire = True
            break
        if a_faire :
          if ( "1D" in les_lignes[0] ) :
            nomfic_bis = "fr1D.%02d" % icpt_1D
            icpt_1D += 1
          else :
            nomfic_bis = "fr2D.%02d" % icpt_2D
            icpt_2D += 1
          fic_1 = os.path.join(rep_calc, nomfic_bis)
          fichier = open (fic_1, "w")
          for ligne in les_lignes[1:] :
            if ( ( "1D" not in ligne ) and ( "2D" not in ligne ) ) :
              fichier.write(ligne)
          fichier.close()
          #print "\t\tajout de %s" % fic_1
          l_fr.append(fic_1)
      elif ( fic[-4:] == '.med' ) :
        fic_hom_med = os.path.join(rep_calc, fic)
        #print "\t\treperage de fic_hom_med =", fic_hom_med
#
# 2. Lancement du post-traitement si des noeuds sont concernés
#
    if l_fr :
#
      if verbose :
        print("l_fr =", l_fr)
        print("fic_hom_med =", fic_hom_med)
#
# 2.1.  La fonction :
#    . prend le maillage brut dans le fichier fic_med_brut
#    . prend la liste des noeuds à bouger pour chaque groupe concerné
#    . prend la géométrie dans le fichier xao_file
#    . retourne le maillage transformé dans le fichier fic_med_new
#
      from FrontTrack import FrontTrack
      ft = FrontTrack()
      ft.track( fic_med_brut, fic_med_new, l_fr, xao_file )
#
# 2.2. Transfert des coordonnées dans le fichier HOMARD MED
#
      #if not fic_hom_med :
        #message = "Impossible de trouver le fichier HOMARD MED dans %s" % rep_calc
        #erreur = 12
        #break
##
      #fic_coords = os.path.join(rep_calc, "coords")
      #erreur, message = change_coords (fic_med_new, fic_coords, verbose)
      ##erreur, message = change_coords_0 (fic_med_new, fic_hom_med, verbose)
      #if erreur :
        #break
#
# 2.3. Ménage de l'ancien fichier MED
#
      if ( fic_med_brut != fic_med_new ) :
        print("Suppression du fichier %s" % fic_med_new)
        os.remove(fic_med_brut)
#
# 3. Renommage du fichier si aucun noeud n'est concerné
#
    else :
#
      if ( fic_med_brut != fic_med_new ) :
        os.rename(fic_med_brut, fic_med_new)
#
# 4. Mise à jour des coordonnées dans le fichier historique HOMARD/MED si des noeuds sont concernés
#
    if l_fr :
#
      erreur, message = maj_coords (rep_calc, fic_med_new, verbose)
#
    break
#
  return erreur, message
#
#========================================================================
#========================================================================
#
def maj_coords (rep_calc, fic_med_calc, verbose=False) :
#
  """
Met à jour les coordonnées du fichier de calcul vers le fichier HOMARD
Entrées :
  rep_calc : répertoire du calcul HOMARD qui est à traiter
  fic_med_calc  : fichier MED du calcul avec les coordonnées après projection
  xao_file : fichier XAO de la géométrie
  """
  if verbose :
    ligne =    "rep_calc     = %s" % rep_calc
    ligne += "\nfic_med_calc = %s" % fic_med_calc
    print(ligne)

  message = ""
  erreur = 0
  while not erreur :
#
# 1. Recherche des inforamtions permanentes dans le fichier de configuration
#
    fic_conf = os.path.join(rep_calc, "HOMARD.Configuration")
    fichier = open (fic_conf, "r")
    les_lignes = fichier.readlines()
    fichier.close()
#
    ligne0 = ""
    icpt = 0
    for ligne in les_lignes :
      #print "\t" + ligne
      for saux in ( "HOMai", "CCNoM" ) :
        if ( saux+"NP1" in ligne ) :
          iaux = ligne.index(saux)
          ligne0 += saux + "N__" + ligne[iaux+8:]
          icpt += 1
      if ( "NumeIter" in ligne ) :
        iaux = ligne.index("NumeIter")
        saux = ligne[iaux+8:-1]
        iaux = int(saux) + 1
        s_iter = "%02d" % iaux
        ligne0 += "NumeIter %s\n" % s_iter
        icpt += 1
#
    if ( icpt != 3 ) :
      message = "Erreur dans le décodage de %s\n" % fic_conf
      message+= ligne0
      erreur = 1
      break
#
# 2. Création du fichier de configuration
#
    fic_conf_sv = os.path.join(rep_calc, "HOMARD.Configuration.majc")
    fichier = open (fic_conf_sv, "w")
#
    ligne = ligne0
    ligne += "ModeHOMA 5\n"
    fic = os.path.join(rep_calc, "Liste.%s.maj_coords.log" % s_iter)
    ligne += "ListeStd %s\n" % fic
    ligne += "CCMaiN__ %s\n" % fic_med_calc
    ligne += "RepeTrav %s\n" % rep_calc
    ligne += "RepeInfo %s\n" % rep_calc
    ligne += "Action   homa\n"
    ligne += "CCAssoci med\n"
    ligne += "EcriFiHO N_SANS_FRONTIERE\n"
    ligne += "MessInfo 10\n"
#
    fichier.write(ligne)
    fichier.close()
#
# 3. Mise à jour
# 3.1. Détermination de l'exécutable
#
    if "HOMARD_REP_EXE_PRIVATE" in os.environ :
      HOMARD_REP_EXE  = os.environ["HOMARD_REP_EXE_PRIVATE"]
    else :
      HOMARD_REP_EXE  = os.environ["HOMARD_REP_EXE"]
#
    if "HOMARD_EXE_PRIVATE" in os.environ :
      HOMARD_EXE  = os.environ["HOMARD_EXE_PRIVATE"]
    else :
      HOMARD_EXE  = os.environ["HOMARD_EXE"]
#
    homard_exe = os.path.join(HOMARD_REP_EXE, HOMARD_EXE)
    if verbose :
      ligne = "homard_exe = %s" % homard_exe
      print(ligne)
#
    if not os.path.isfile(homard_exe) :
      message = "homard_exe = %s" % homard_exe
      message += "\nCe fichier executable n'existe pas."
      erreur = 31
      break
#
# 3.2. Lancement
#
    fic_conf = os.path.join(rep_calc, "HOMARD.Configuration")
    shutil.copyfile(fic_conf_sv, fic_conf)
#
    os.chdir(rep_calc)
    erreur = os.system (homard_exe)
#
    break
#
  return erreur, message
#
#========================================================================
#========================================================================
#
