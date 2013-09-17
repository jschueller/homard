#!/usr/bin/env python
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
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2010, 2013
"""
__revision__ = "V1.5"
#
import os
#
# ==================================
# Repertoire a personnaliser
# Ce repertoire contiendra les fichiers de resultats : maill.01.med, maill.02.med
if os.environ.has_key("LOGNAME") :
  user = os.environ ["LOGNAME"]
else :
  user = "anonymous"
dircase = os.path.join( os.sep, "tmp", "HOMARD_"+user)
if not os.path.isdir(dircase) :
  os.mkdir (dircase)
# ==================================
# Ce repertoire contient les fichiers de donnees : tutorial_5.00.med, tutorial_5.fr.med
pathHomard = os.getenv('HOMARD_ROOT_DIR')
data_dir = os.path.join(pathHomard, "share/doc/salome/gui/HOMARD/fr/_downloads")
#
import salome
salome.salome_init()
import HOMARD
#
homard = salome.lcc.FindOrLoadComponent("FactoryServer", "HOMARD")
study_main = salome.myStudyManager.NewStudy("HOMARD")
homard.SetCurrentStudy(salome.myStudy)
#
# Creation of the boundaries
# ==========================
# Creation of the discrete boundary Boun_1
Boun_1 = homard.CreateBoundaryDi('Boun_1', 'MAIL_EXT', data_dir+'/tutorial_5.fr.med')
#
# Creation of the zones
# =====================
# Creation of the disk with hole enveloppe
enveloppe = homard.CreateZoneDiskWithHole( 'enveloppe', 0., 0., 250., 193., 1 )
# Creation of the rectangle quart_sup
quart_sup = homard.CreateZoneBox2D( 'quart_sup', 0., 250., 0., 250., 1 )
#
# Hypothesis
# ==========
# Creation of the hypothesis Hypo_1
Hypo_1 = homard.CreateHypothesis('Hypo_1')
Hypo_1.SetAdapRefinUnRef(0, 1, 0)
Hypo_1.AddZone('enveloppe', 1)
# Creation of the hypothesis Hypo_2
Hypo_2 = homard.CreateHypothesis('Hypo_2')
Hypo_2.SetAdapRefinUnRef(0, 1, 0)
Hypo_2.AddZone('quart_sup', 1)
#
# Case "Case_1"
# =============
Case_1 = homard.CreateCase('Case_1', 'COEUR_2D', data_dir+'/tutorial_5.00.med')
Case_1.SetDirName(dircase)
Case_1.SetConfType(3)
Case_1.AddBoundaryGroup('Boun_1', '')
#
# Iteration "Iter_1"
# ==================
Iter_1 = Case_1.NextIteration('Iter_1')
Iter_1.SetMeshName('COEUR_2D_01')
Iter_1.SetMeshFile(dircase+'/maill.01.med')
Iter_1.AssociateHypo('Hypo_1')
codret = Iter_1.Compute(1, 2)
#
# Iteration "Iter_2"
# ==================
Iter_2 = Iter_1.NextIteration('Iter_2')
Iter_2.SetMeshName('COEUR_2D_02')
Iter_2.SetMeshFile(dircase+'/maill.02.med')
Iter_2.AssociateHypo('Hypo_2')
codret = Iter_2.Compute(1, 2)


if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
