.. _gui_divers:

Miscellaneous
#############
References
**********
.. index:: single: reference

The HOMARD software was subject of publications techniques in the course of conferences these last years. References of main documents are presented here.

Main reference
==============
For a reference to HOMARD, use:

G. Nicolas and T. Fouquet, Adaptive Mesh Refinement for Conformal Hexahedral Meshes, "*Finite Elements in Analysis and Design*", Vol. 67, pp. 1-12, 2013, doi:10.1016/j.finel.2012.11.008

`Available here <http://dx.doi.org/10.1016/j.finel.2012.11.008>`_

Splitting meshing
=================

  * G. Nicolas, T. Fouquet, Conformal hexaedral meshes and adaptive mesh refinement, VI International Conference on Adaptive Modeling and Siumulation, "*ADMOS 2013*", J.P. Moitinho de Almeida, P. Diez, C. Tiago and N. Pares (Eds), Lisbonne, pp. 515-526, 2013
  * G. Nicolas, T. Fouquet, Hexaedral mesh adaptation for finite volume methods, III International Conference on Adaptive Modeling and Siumulation, "*ADMOS 2007*", K. Runesson, P. Diez (Eds), Goteborg, pp. 174-177, 2007
  * G. Nicolas, F. Arnoux-Guisse, O. Bonnin, Adaptive meshing for 3D finite element software, IX International Conference on Finite Elements in Fluids, Venise, Italie, 15-21 Octobre 1995.
  * G. Nicolas, F. Arnoux-Guisse, O. Bonnin, Un logiciel d'adaptation de maillage en 2D et 3D, 27ème Congrès d'Analyse Numérique, Super-Besse, France, May 29-June 2, 1995.

Error estimators
================

  * A. Ern, S. Meunier, A posteriori error analysis of Euler-Galerkin approximations to coupled elliptic-parabolic problems", ESAIM: M2AN 43 (2009) 353-375.
  * J. Delmas, Stratégies de controle d'erreur en calcul de structures industrielles., PhD of the Université de Picardie, France, April 2008
  * S. Meunier, Analyse d'erreur a posteriori pour les couplages hydro-mécaniques et mise en oeuvre dans Code_Aster, PhD of the Ecole Nationale des Ponts et Chaussées, France, November 2007.
  * J. Delmas, P. Coorevits, P.-B. Badel and M. Guessasma, An explicit estimator for goal oriented H-Adaptivity with mesh optimaly criteria, III International Conference on Adaptive Modeling and Siumulation, "*ADMOS 2007*", K. Runesson, P. Diez (Eds), Goteborg, pp. 93-96, 2007.
  * P. Destuynder, B. Métivet, Estimation d'erreur explicite dans une méthode d'éléments finis conforme, Compte Rendu Académie des Sciences Paris, tome 323, Série I, p. 679-684, 1996.
  * P. Destuynder, B. Métivet, Estimation d'erreur explicite pour une méthode d'éléments finis non conforme, Compte Rendu Académie des Sciences Paris, tome 322, Série I, p. 1081-1086, 1996.
  * C. Bernardi, O. Bonnin, C. Langouet, B. Métivet, Residual Error Indicators for Linear Problems - Extension to the Navier-Stokes Equations, IX International Conference on Finite Elements in Fluids, Venise, Italie, 15-21 Octobre 1995.
  * F. Arnoux-Guisse, O. Bonnin, L. Léal De Sousa, G. Nicolas, An adaptive finite element method for turbulent flow simulation, ICFD Conference on Numerical Methods for Fluid Dynamics, University of Oxford, Grande-Bretagne, 3-6 Avril 1995.
  * O. Bonnin, B. Métivet, G. Nicolas, F. Arnoux-Guisse, L. Léal de Sousa, Adaptive Meshing for N3S Fluid Mechanics Code, "*Computational Fluid Dynamics '94*", ECCOMAS Stuttgart, Allemagne, pp. 201-208, Wiley 1994.

Applications
============

  * S. Meunier, R. Fernandes, Mesh Adaptation for Coupled Hydro-Mechanical Industrial Studies, V International Conference on Adaptive Modeling and Siumulation, "*ADMOS 2011*", D. Aubry, P. Diez, B. Tie and N. Pares (Eds), Paris, pp. 337-338, 2011
  * O. Hartmann, O. Bonnin, D. Gasser, An Adaptive Meshing for Turbomachinery Geometries, "*Computational Fluid Dynamics '98*", ECCOMAS Athènes, Greece, Wiley 1998.


Evolutions of the module
************************
.. index:: single: evolution

Here are the main evolutions de HOMARD from the first release in SALOME 6.5.

SALOME RELEASE 6.6 :
   - Interface with med 3.0.6
   - Default values for the time steps
   - New element types: TRIA7 and QUAD9
   - Optional output into the MED file of the level of refinement of every element

SALOME RELEASE 7.1 :
   - Correction of a bug in the filtering of the refinement by groups
   - Driving of the adaptation by a threshold that is based upon the mean and the standard deviation (see :ref:`tui_create_hypothese`)
   - TUI: the last time step for the driving instant can be selected by SetTimeStepRankLast (see :ref:`tui_create_iteration`)
   - The destruction of the objects is available (GUI and TUI)
   - The TUI functions are modified: they act onto the objects and no more by the names:
     ``homard.AssociateIterHypo(iter_name,hypo_name)`` becomes ``iter.AssociateHypo(hypo_name)``, ``homard.AssociateHypoZone(hypo_name,zone_name,type_use)`` becomes ``hypo.AddZone(zone_name,type_use)``, ``homard.CreateIteration(iter_name,iter_parent_name)`` becomes ``case.NextIteration(iter_name)`` ou ``iter.NextIteration(iter_name)``
   - Addition of a function:
     ``cas.LastIteration()`` : returns the last iteration of the case (see :ref:`tui_create_iteration`)
   - Mesh analysis (see :ref:`gui_mesh_info`)

SALOME RELEASE 7.2.0 :
   - A cone can be used as a support for a 2D boundary (see :ref:`tui_create_boundary`)
   - The result can be published or not published in SMESH (see :ref:`tui_create_iteration`)
     ``iter.Compute(option)`` becomes ``iter.Compute(option1, option2)``
   - A serie of iterations that is stored in a directory can be followed (see :ref:`gui_create_case`)






