.. _gui_create_zone:

The zone
========
.. index:: single: zone
.. index:: single: 2D

L'objet zone contient toutes les définitions géométriques permettant de décrire une zone à raffiner.

En 3D, il existe quatre types de zone :

  - Parallélépipède
  - Cylindre
  - Tuyau
  - Sphère

Leurs analogues en 2D sont :

  - Rectangle
  - Disque
  - Disque percé

Le principe du raffinement selon des zones est le suivant. Chaque arête de maille dont les deux extrémités
sont incluses dans une même zone sera coupée. Ensuite HOMARD applique l'algorithme de traitement de la
conformité pour produire un maillage correct.

.. note::
  Les valeurs proposées par défaut pour les dimensions des zones tiennent compte de la géométrie du maillage.

Name of the zone
""""""""""""""""
Un nom de zone est proposé automatiquement : Zone_1, Zone_2, etc. Ce nom peut être modifié. Il ne doit pas avoir été déjà utilisé pour une autre zone.

Box
"""
.. index:: single: box

Le parallélépipède est obligatoirement parallèle aux axes de coordonnées. Il est défini par ses extrêmes dans chaque direction.

.. image:: images/create_zone_1.png
   :align: center

Cylindre
""""""""
.. index:: single: cylindre

Le cylindre est défini par son axe, un point de base positionné sur l'axe, sa hauteur et son rayon. L'axe est défini par un vecteur qui doit être correctement orienté : on retiendra le volume partant de la base dans la direction du vecteur jusqu'à la hauteur retenue. La norme de ce vecteur n'est pas nécessairement égale à 1.

.. image:: images/create_zone_2.png
   :align: center

Pipe
""""
.. index:: single: pipe

Le cylindre est défini par son axe, un point de base positionné sur l'axe, sa hauteur et ses rayons interne et externe. L'axe est défini par un vecteur qui doit être correctement orienté : on retiendra le volume partant de la base dans la direction du vecteur jusqu'à la hauteur retenue. La norme de ce vecteur n'est pas nécessairement égale à 1.

.. image:: images/create_zone_3.png
   :align: center

Sphere
""""""
.. index:: single: sphere

La sphère est définie par son centre et son rayon.

.. image:: images/create_zone_4.png
   :align: center

Rectangle
"""""""""
.. index:: single: rectangle

Le rectangle est obligatoirement parallèle aux axes de coordonnées. Il est défini par ses extrêmes dans chacune des directions valides. La coordonnée constante est affichée pour information, mais n'est pas modifiable.

.. image:: images/create_zone_21.png
   :align: center

Disk
""""
.. index:: single: disk

Le disque est obligatoirement dans le plan des axes de coordonnées. Il est défini par son centre et son rayon. La coordonnée constante est affichée pour information, mais n'est pas modifiable.

.. image:: images/create_zone_22.png
   :align: center

Disk with a hole
""""""""""""""""
.. index:: single: disk with a hole

Le disque avec trou est obligatoirement dans le plan des axes de coordonnées. Il est défini par son centre et ses rayons externe et interne. La coordonnée constante est affichée pour information, mais n'est pas modifiable.

.. image:: images/create_zone_23.png
   :align: center



Corresponding python functions
""""""""""""""""""""""""""""""
Look :ref:`tui_create_zone`
