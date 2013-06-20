.. _gui_create_iteration:

The iteration
=============
.. index:: single: iteration

La définition d'une iteration se fait par la donnée des informations suivantes :

  - L'iteration précédente
  - Le nom du maillage résultat
  - L'hypothesis utilisée
  - Eventuellement, le fichier du champ d'indicateurs d'erreur

.. image:: images/create_iteration_1.png
   :align: center

Name of the iteration
"""""""""""""""""""""
Un nom de cas est proposé automatiquement : Iter_1, Iter_2, etc. Ce nom peut être modifié. Il ne doit pas avoir été utilisé pour une iteration précédente.

The previous iteration
""""""""""""""""""""""
L'iteration précédente est choisie dans l'arbre d'étude. Le nom du maillage correspondant sera affiché.

.. index:: single: mesh;result

The name of the resulting mesh
""""""""""""""""""""""""""""""
L'iteration en cours de création produira un maillage. Ce maillage sera connu sous un nom. Ce nom est fourni en le tapant dans la zone de texte. Par défaut, on propose un nom identique à celui de l'iteration précédente.

.. index:: single: field
.. index:: single: MED

The field
"""""""""
Pour créer ou utiliser une hypothesis d'adaptation basée sur un champ exprimé sur le maillage, on doit fournir le fichier où se trouve le champ. C'est également le cas si on veut interpoler des champs du maillage n au maillage n+1. Ce fichier est au format MED. Classiquement, il aura été produit par le logiciel de calcul avec lequel on travaille. Le nom du fichier peut être fourni, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.


.. image:: images/create_iteration_2.png
   :align: center

Dans le cas où des pas de temps ont été définis, une solution simple consiste à traiter les champs au dernier pas de temps enregistré dans le fichier. Si on veut définir un autre pas de temps, on coche le bouton "*Pas de temps choisi*". Les valeurs de 'Pas de temps' et de 'Numéro d'ordre' sont celles correspondant à la convention MED (time step / rank). Ces valeurs dépendent de la logique qui a été retenue par le logiciel qui a écrit le fichier. Souvent ces deux valeurs sont identiques mais il arrive que l'on disjoigne les pas de temps et les intervalles d'archivage.

.. image:: images/create_iteration_3.png
   :align: center

.. index:: single: hypothesis

The hypothesis
""""""""""""""
L'iteration en cours pilotera l'adaptation par HOMARD selon un scénario défini dans une hypothesis. Celle-ci est choisie dans la liste des hypothesiss existantes.

Au démarrage, il faut créer une première hypothesis par activation du bouton "*Nouveau*" (voir :ref:`gui_create_hypothese`) :

.. image:: images/create_iteration_4.png
   :align: center

Ensuite, si une hypothesis précédemment définie convient, il suffit de la sélectionner dans la liste proposée. Sinon, il faut créer une nouvelle hypothesis par activation du bouton "*Nouveau*", puis la sélectionner dans la liste proposée :

.. image:: images/create_iteration_5.png
   :align: center


.. note::
  Si on envisage une adaptation selon les valeurs d'un champ sur le maillage, il faut avoir renseigné les informations sur ce champ avant de créer une nouvelle hypothesis.

.. index:: single: object browser

Object browser
""""""""""""""
A l'issue de cette création d'iteration, l'arbre d'études a été enrichi. On y trouve l'iteration initiale, identifiée par le nom du maillage qui a été lu dans le fichier fourni, l'iteration courante, identifiée par son nom. On trouve aussi l'hypothesis qui lui est attachée. L'icône en regard de l'iteration permet de différencier les iterations calculées ou non.

.. image:: images/create_iteration_6.png
   :align: center

Quand plusieurs iterations s'enchaînent, leur hypothesis est visible dans l'arbre d'étude. On remarquera dans la figure ci-après que deux iterations peuvent partager la même hypothesis.

.. image:: images/create_iteration_7.png
   :align: center

Corresponding python functions
""""""""""""""""""""""""""""""
Look :ref:`tui_create_iteration`
