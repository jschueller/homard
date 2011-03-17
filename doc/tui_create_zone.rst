.. _tui_create_zone:

La zone
=======

.. index:: single: zone
.. index:: single: boite
.. index:: single: sphere

Les variables sont décrites dans :ref:`gui_create_zone`.

Méthodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+===============================================================+
| .. module:: CreateZone                                        |
|                                                               |
| **CreateZone(zone_name)**                                     |
|                                                               |
|     - ``zone_name`` : le nom de la zone                       |
+---------------------------------------------------------------+

Méthodes de la classe zone
""""""""""""""""""""""""""

+---------------------------------------------------------------+
+===============================================================+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de la zone                                |
+---------------------------------------------------------------+
| .. module:: SetZoneType                                       |
|                                                               |
| **SetZoneType(zone_type)**                                    |
|                                                               |
|     - ``zone_type`` : entier précisant le type de zone        |
|                                                               |
|         * 2 : parallélépipède                                 |
|         * 4 : sphère                                          |
+---------------------------------------------------------------+
| .. module:: SetBox                                            |
|                                                               |
| **SetBox(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax)**                |
|                                                               |
|     - ``Xmin``, ``Xmax`` : X mini, X maxi                     |
|     - etc.                                                    |
+---------------------------------------------------------------+
| .. module:: SetSphere                                         |
|                                                               |
| **SetSphere(Xcen, Ycen, Zcen, R)**                            |
|                                                               |
|     - ``Xcen`` : X du centre                                  |
|     - ``Ycen`` : Y du centre                                  |
|     - ``Zcen`` : Z du centre                                  |
|     - ``R`` : rayon de la sphère                              |
+---------------------------------------------------------------+


Exemple
"""""""
La création de l'objet zone_1 se fait ainsi : ::

    zone_1 = homard.CreateZone("Zone_2")
    zone_1.SetTypeZone(4)
    zone_1.SetSphere(12.3, 3.4, .56, 6.5)


