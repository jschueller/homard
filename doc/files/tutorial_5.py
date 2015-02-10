#!/usr/bin/env python
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
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2010, 2014
"""
__revision__ = "V1.8"
#
import os
import sys
#
# ==================================
pathHomard = os.getenv('HOMARD_ROOT_DIR')
# Repertoire des donnees du tutorial
data_dir = os.path.join(pathHomard, "share", "doc", "salome", "gui", "HOMARD", "fr", "_downloads")
data_dir = os.path.normpath(data_dir)
sys.path.append(data_dir)
from tutorial_util import gzip_gunzip
from tutorial_util import creation_dircase
# ==================================
dircase = creation_dircase(5)
gzip_gunzip(data_dir, 5, -1)
# ==================================
#
import salome
salome.salome_init()
import HOMARD
#
homard = salome.lcc.FindOrLoadComponent("FactoryServer", "HOMARD")
study_main = salome.myStudyManager.NewStudy("HOMARD")
homard.SetCurrentStudy(salome.myStudy)
#
# Frontiere
# =========
# Creation of the discrete boundary Boun_5_1
Boun_5_1 = homard.CreateBoundaryDi('Boun_5_1', 'MAIL_EXT', data_dir+'/tutorial_5.fr.med')
#
# Creation des zones
# ==================
# Creation of the disk with hole enveloppe
enveloppe = homard.CreateZoneDiskWithHole( 'enveloppe', 0., 0., 250., 193., 1 )
# Creation of the rectangle quart_sup
quart_sup = homard.CreateZoneBox2D( 'quart_sup', 0., 250., 0., 250., 1 )
#
# Hypotheses
# ==========
# Creation of the hypothesis Hypo_5
Hypo_5 = homard.CreateHypothesis('Hypo_5')
Hypo_5.AddZone('enveloppe', 1)
# Creation of the hypothesis Hypo_5_bis
Hypo_5_bis = homard.CreateHypothesis('Hypo_5_bis')
Hypo_5_bis.AddZone('quart_sup', 1)
#
# Cas
# ===
Case_5 = homard.CreateCase('Case_5', 'COEUR_2D', data_dir+'/tutorial_5.00.med')
Case_5.SetDirName(dircase)
Case_5.SetConfType(3)
Case_5.AddBoundaryGroup('Boun_5_1', '')
#
# Iteration "Iter_5_1"
# ====================
Iter_5_1 = Case_5.NextIteration('Iter_5_1')
Iter_5_1.SetMeshName('COEUR_2D_01')
Iter_5_1.SetMeshFile(dircase+'/maill.01.med')
Iter_5_1.AssociateHypo('Hypo_5')
error = Iter_5_1.Compute(1, 2)
#
# Iteration "Iter_5_2"
# ====================
Iter_5_2 = Iter_5_1.NextIteration('Iter_5_2')
Iter_5_2.SetMeshName('COEUR_2D_02')
Iter_5_2.SetMeshFile(dircase+'/maill.02.med')
Iter_5_2.AssociateHypo('Hypo_5_bis')
error = Iter_5_2.Compute(1, 2)

# ==================================
gzip_gunzip(data_dir, 5, 1)
# ==================================

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
