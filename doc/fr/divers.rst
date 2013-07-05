.. _divers:

Divers
######

Références
**********
.. index:: single: référence

Le logiciel HOMARD a fait l'objet de publications techniques au cours de conférences ces dernières années. Les références des principaux documents sont présentées ici.

Référence principale
====================

Pour une référence à HOMARD, utiliser :

G. Nicolas and T. Fouquet, Adaptive Mesh Refinement for Conformal Hexahedral Meshes, "*Finite Elements in Analysis and Design*", Vol. 67, pp. 1-12, 2013, doi:10.1016/j.finel.2012.11.008

`Accessible en cliquant ici <http://dx.doi.org/10.1016/j.finel.2012.11.008>`_


Découpage de maillage
=====================

  * G. Nicolas, T. Fouquet, Conformal hexaedral meshes and adaptive mesh refinement, VI International Conference on Adaptive Modeling and Siumulation, "*ADMOS 2013*", J.P. Moitinho de Almeida, P. Diez, C. Tiago and N. Pares (Eds), Lisbonne, pp. 515-526, 2013
  * G. Nicolas, T. Fouquet, Hexaedral mesh adaptation for finite volume methods, III International Conference on Adaptive Modeling and Siumulation, "*ADMOS 2007*", K. Runesson, P. Diez (Eds), Goteborg, pp. 174-177, 2007
  * G. Nicolas, F. Arnoux-Guisse, O. Bonnin, Adaptive meshing for 3D finite element software, IX International Conference on Finite Elements in Fluids, Venise, Italie, 15-21 Octobre 1995.
  * G. Nicolas, F. Arnoux-Guisse, O. Bonnin, Un logiciel d'adaptation de maillage en 2D et 3D, 27ème Congrès d'Analyse Numérique, Super-Besse, France, 29 mai-2 juin 1995.

Estimateurs d'erreurs
=====================

  * A. Ern, S. Meunier, A posteriori error analysis of Euler-Galerkin approximations to coupled elliptic-parabolic problems", ESAIM: M2AN 43 (2009) 353-375.
  * J. Delmas, Stratégies de controle d'erreur en calcul de structures industrielles., Thèse de l'Université de Picardie, France, avril 2008
  * S. Meunier, Analyse d'erreur a posteriori pour les couplages hydro-mécaniques et mise en oeuvre dans Code_Aster, Thèse de l'Ecole Nationale des Ponts et Chaussées, France, novembre 2007.
  * J. Delmas, P. Coorevits, P.-B. Badel and M. Guessasma, An explicit estimator for goal oriented H-Adaptivity with mesh optimaly criteria, III International Conference on Adaptive Modeling and Siumulation, "*ADMOS 2007*", K. Runesson, P. Diez (Eds), Goteborg, pp. 93-96, 2007.
  * P. Destuynder, B. Métivet, Estimation d'erreur explicite dans une méthode d'éléments finis conforme, Compte Rendu Académie des Sciences Paris, tome 323, Série I, p. 679-684, 1996.
  * P. Destuynder, B. Métivet, Estimation d'erreur explicite pour une méthode d'éléments finis non conforme, Compte Rendu Académie des Sciences Paris, tome 322, Série I, p. 1081-1086, 1996.
  * C. Bernardi, O. Bonnin, C. Langouet, B. Métivet, Residual Error Indicators for Linear Problems - Extension to the Navier-Stokes Equations, IX International Conference on Finite Elements in Fluids, Venise, Italie, 15-21 Octobre 1995.
  * F. Arnoux-Guisse, O. Bonnin, L. Léal De Sousa, G. Nicolas, An adaptive finite element method for turbulent flow simulation, ICFD Conference on Numerical Methods for Fluid Dynamics, University of Oxford, Grande-Bretagne, 3-6 Avril 1995.
  * O. Bonnin, B. Métivet, G. Nicolas, F. Arnoux-Guisse, L. Léal de Sousa, Adaptive Meshing for N3S Fluid Mechanics Code, "*Computational Fluid Dynamics '94*", ECCOMAS Stuttgart, Allemagne, pp. 201-208, Wiley 1994.

Applications
============
  * S. Meunier, R. Fernandes, Mesh Adaptation for Coupled Hydro-Mechanical Industrial Studies, V International Conference on Adaptive Modeling and Siumulation, "*ADMOS 2011*", D. Aubry, P. Diez, B. Tie and N. Pares (Eds), Paris, pp. 337-338, 2011
  * O. Hartmann, O. Bonnin, D. Gasser, An Adaptive Meshing for Turbomachinery Geometries, "*Computational Fluid Dynamics '98*", ECCOMAS Athènes, Grèce, Wiley 1998.

Evolutions du module
********************
.. index:: single: évolution

On trouvera ici les principales évolutions de HOMARD à partir de la première version livrée dans SALOME 6.5.

SALOME VERSION 6.6 :
   - Interfaçage avec med 3.0.6
   - Valeurs par défaut des instants
   - Acceptation des mailles de type TRIA7 et QUAD9
   - Option de sortie dans le fichier MED du niveau de raffinement atteint dans chaque maille

SALOME VERSION 7.1 :
   - Correction d'une anomalie sur le filtrage du raffinement par les groupes
   - Pilotage de l'adaptation par un seuil basé sur la moyenne et l'écart-type (voir :ref:`tui_create_hypothese`)
   - En TUI, choix du dernier instant comme instant de pilotage par SetTimeStepRankLast (voir :ref:`tui_create_iteration`)
   - Possibilité de détruire les objets (GUI et TUI)
   - Modification des fonctions TUI pour qu'elles agissent sur les objets et non plus sur les noms :
     ``homard.AssociateIterHypo(iter_name,hypo_name)`` devient ``iter.AssociateHypo(hypo_name)``, ``homard.AssociateHypoZone(hypo_name,zone_name,type_use)`` devient ``hypo.AddZone(zone_name,type_use)``, ``homard.CreateIteration(iter_name,iter_parent_name)`` devient ``case.NextIteration(iter_name)`` ou ``iter.NextIteration(iter_name)``
   - Ajout de fonctions :
     ``cas.LastIteration()`` : retourne la dernière itération de la descendance du cas (voir :ref:`tui_create_iteration`)
   - Analyse de maillages (voir :ref:`gui_mesh_info`)

SALOME VERSION 7.2.0 :
   - Possibilité d'utiliser un cone comme support de frontiere 2D (voir :ref:`tui_create_boundary`)
   - Choix de publier ou non le résultat dans SMESH (voir :ref:`tui_create_iteration`)
     ``iter.Compute(option)`` devient ``iter.Compute(option1, option2)``
   - Possibilité de poursuivre une suite d'itérations archivées dans un répertoire (voir :ref:`gui_create_case`)

SALOME VERSION 7.2.1 :
   - Documentation en anglais

Contact
*******
.. index:: single: Contact

Gérald NICOLAS, Responsable du Logiciel

Adresse :
EDF R&D, 1, avenue du Général de Gaulle, 92141 CLAMART Cedex, FRANCE

Téléphone : (33/0) 1.47.65.56.94

Email : Gerald.Nicolas[at]edf.fr


Thierry FOUQUET

Adresse :
EDF R&D, 1, avenue du Général de Gaulle, 92141 CLAMART Cedex, FRANCE

Téléphone : (33/0) 1.47.65.41.45

Email : Thierry.Fouquet[at]edf.fr


Vraiment divers ...
*******************

HOMARD est un acronyme pour :
 - Outil de
 - Maillage
 - Adaptatif par
 - Raffinement et
 - Déraffinement

Notre mascotte était toute trouvée dans `la ville du homard <http://www.shediac.org>`_  : |M|

.. |M| image:: ../images/mascotte.gif
   :align: middle
   :alt: Mascotte
   :width: 144
   :height: 94

West led the aaaaaaaaa |H| ffffffff |S| ccccccccccccccccc.

.. |H| image:: ../images/mascotte.gif
   :width: 144
   :height: 94
.. |S| image:: ../images/dec_tria_1.gif
   :width: 399
   :height: 88




