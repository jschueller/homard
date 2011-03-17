#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-
"""
Exemple de couplage HOMARD-Salome
Copyright EDF-R&D 1996, 2010
"""
__revision__ = "V1.0"
#
import salome
salome.salome_init()
import HOMARD
#
homard = salome.lcc.FindOrLoadComponent("FactoryServer", "HOMARD")
study_main = salome.myStudyManager.NewStudy("HOMARD")
homard.SetCurrentStudy(salome.myStudy)
#
repcas = "/tmp"
#
# Creation of the zones
# =====================
# Box "Zone_0"
Zone_0 = homard.CreateZone('Zone_0', 2)
Zone_0.SetBox(-0.1, 1.1, -0.1, 1.1, 0.9, 1.1)

# Sphere "Zone_1"
Zone_1 = homard.CreateZone('Zone_1', 4)
Zone_1.SetSphere(0., 0., 0., 1.05)
#
# Hypothesis "Hypo_0"
# ===================
Hypo_0 = homard.CreateHypothesis('Hypo_0')
Hypo_0.SetAdapRefinUnRef(0, 1, 0)
homard.AssociateHypoZone('Zone_1', 'Hypo_0')
homard.AssociateHypoZone('Zone_0', 'Hypo_0')
#
# Case "Case_0"
# =============
Case_0 = homard.CreateCase('Case_0', 'MZERO', repcas+'/tutorial_2.00.med')
Case_0.SetDirName(repcas)
#
# Iteration "Iter_0"
# ==================
Iter_0 = homard.CreateIteration('Iter_0', Case_0.GetIter0Name())
Iter_0.SetMeshName('MUN')
Iter_0.SetMeshFile(repcas+'/maill.01.med')
homard.AssociateIterHypo('Iter_0', 'Hypo_0')
codret = homard.Compute('Iter_0', 1)

if salome.sg.hasDesktop():
  salome.sg.updateObjBrowser(1)
