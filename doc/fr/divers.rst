.. _divers:

Divers
######

Références
**********
.. index:: single: référence

Pour une référence à HOMARD, utiliser :

G. Nicolas and T. Fouquet, Adaptive Mesh Refinement for Conformal Hexahedral Meshes, "*Finite Elements in Analysis and Design*", Vol. 67, pp. 1-12, 2013, doi:10.1016/j.finel.2012.11.008

`Accessible en cliquant ici <http://dx.doi.org/10.1016/j.finel.2012.11.008>`_

D'autres références sont disponibles sur le site de `HOMARD <http://www.code-aster.org/outils/homard/fr/divers.html>`_

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
   - Ajout de fonctions :
     ``iter.SetInfoCompute(MessInfo)`` : précise des options pour suivre le calcul de l'itération (voir :ref:`tui_create_iteration`)



