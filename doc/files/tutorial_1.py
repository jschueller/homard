#!/usr/bin/env python
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
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2010, 2014
"""
__revision__ = "V1.9"
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
dircase = creation_dircase(1)
gzip_gunzip(data_dir, 1, -1)
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
# Hypotheses
# ==========
Hypo_1 = homard.CreateHypothesis('Hypo_1')
Hypo_1.SetUnifRefinUnRef(1)
#
# Cas
# ===
Case_1 = homard.CreateCase('Case_1', 'MAILL', data_dir+'/tutorial_1.00.med')
Case_1.SetDirName(dircase)
Case_1.SetConfType(1)
#
# Iterations
# ==========
# Iteration "Iter_1_1"
Iter_1_1 = Case_1.NextIteration('Iter_1_1')
Iter_1_1.SetMeshName('MESH')
Iter_1_1.SetMeshFile(dircase+'/maill.01.med')
Iter_1_1.AssociateHypo('Hypo_1')
error = Iter_1_1.Compute(1, 2)

# Iteration "Iter_1_2"
Iter_1_2 = Iter_1_1.NextIteration('Iter_1_2')
Iter_1_2.SetMeshName('MESH')
Iter_1_2.SetMeshFile(dircase+'/maill.02.med')
Iter_1_2.AssociateHypo('Hypo_1')
error = Iter_1_2.Compute(1, 2)

# Iteration "Iter_1_3"
Iter_1_3 = Iter_1_2.NextIteration('Iter_1_3')
Iter_1_3.SetMeshName('MESH')
Iter_1_3.SetMeshFile(dircase+'/maill.03.med')
Iter_1_3.AssociateHypo('Hypo_1')
error = Iter_1_3.Compute(1, 2)

# ==================================
gzip_gunzip(data_dir, 1, 1)
# ==================================

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
