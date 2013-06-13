.. _tui_create_boundary_en:

The boundary
============

.. index:: single: boundary
.. index:: single: cylindre
.. index:: single: sphere

The variables are described in :ref:`gui_create_boundary_en`.

Methods of the class homard
"""""""""""""""""""""""""""
These methods returns an instance of the class boundary.

+----------------------------------------------------------------------------------------+
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryDi                                                           |
|                                                                                        |
| **CreateBoundaryDi(boundary_name, mesh_name, mesh_file)**                              |
|     Returns an instance of the class ``boundary``, type discrete after its creation    |
|                                                                                        |
|     - ``boundary_name``: the name of the discrete boundary                             |
|     - ``mesh_name``: the name of the mesh of the boundary                              |
|     - ``mesh_file``: the name of the file for this mesh                                |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryCylinder                                                     |
|                                                                                        |
| **CreateBoundaryCylinder(boundary_name, Xcen, Ycen, Zcen, Xaxe, Yaxe, Zaxe, R)**       |
|     Returns an instance of the class ``boundary`` analytical type cylindrical          |
|     after its creation                                                                 |
|                                                                                        |
|     - ``boundary_name``: the name of the analytical boundary based on a cylinder       |
|     - ``Xcen``, ``Ycen``, ``Zcen``: coordinates of a point on the axis of the cylinder |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe``: vector of the axis                                 |
|     - ``R``: radius of the cylinder                                                    |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundarySphere                                                       |
|                                                                                        |
| **CreateBoundarySphere(boundary_name, Xcen, Ycen, Zcen, R)**                           |
|     Returns an instance of the class ``boundary`` analytical type spherical            |
|     after its creation                                                                 |
|                                                                                        |
|     - ``boundary_name``: the name of the boundary analytique based on a sphere         |
|     - ``Xcen``, ``Ycen``, ``Zcen``: coordinates of the centre of the sphere            |
|     - ``R``: radius of the sphere                                                      |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryConeA                                                        |
|                                                                                        |
| **CreateBoundaryConeA(boundary_name, Xaxe, Yaxe, Zaxe, Angle, Xcen, Ycen, Zcen)**      |
|     Returns an instance of the class ``boundary`` analytical type conical              |
|     after its creation                                                                 |
|                                                                                        |
|     - ``boundary_name``: the name of the boundary analytique based on a cone           |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe``: vector of the axis                                 |
|     - ``Angle``: opening angle of the cone in degree (between 0 and 90)                |
|     - ``Xcen``, ``Ycen``, ``Zcen``: coordinates of the centre of the cone              |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryConeR                                                        |
|                                                                                        |
| **CreateBoundaryConeR(boundary_name, Xc1, Yc1, Zc1, R1, Xc2, Yc2, Zc2, R2)**           |
|     Returns an instance of the class ``boundary`` analytical type conical              |
|     after its creation                                                                 |
|                                                                                        |
|     - ``boundary_name``: the name of the boundary analytique based on a cone           |
|     - ``Xc1``, ``Yc1``, ``Zc1``: coordinates of the first centre of the cone           |
|     - ``R1``: radius of the cone at the first centre of the cone                       |
|     - ``Xc2``, ``Yc2``, ``Zc2``: coordinates of the second centre of the cone          |
|     - ``R2``: radius of the cone at the second centre of the cone                      |
+----------------------------------------------------------------------------------------+

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetBoundary                                       |
|                                                               |
| **GetBoundary(boundary_name)**                                |
|     Returns the instance of the class classe ``boundary``     |
|     known by its name                                         |
|                                                               |
|     - ``boundary_name``: the name of the boundary             |
+---------------------------------------------------------------+
| .. module:: GetAllBoundarysName                               |
|                                                               |
| **GetAllBoundarysName()**                                     |
|     Returns the list of the names of all the existing         |
|     boundaries                                                |
|                                                               |
+---------------------------------------------------------------+

Methods of the class cas
"""""""""""""""""""""""""
See also in :ref:`tui_create_case_en`.

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddBoundaryGroup                                  |
|                                                               |
| **AddBoundaryGroup(boundary, group)**                         |
|     Add a boundary to the definition of a case                |
|                                                               |
|     - ``boundary``: nom d'une frontière courbe à suivre       |
|                                                               |
|     Pour une frontière discrete:                              |
|                                                               |
|     . si toutes les lignes courbes sont suivies, le second    |
|       argument est une chaîne vide.                           |
|     . si seulement certaines lignes courbes sont suivies,     |
|       ``group`` est the name d'un groupe de segments à suivre |
|                                                               |
|     Pour une frontière analytique:                            |
|                                                               |
|     - ``group``: nom d'un groupe de faces placées sur la      |
|       frontière                                               |
+---------------------------------------------------------------+

Methods of the class boundary
""""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne the name of the boundary                         |
+---------------------------------------------------------------+
| .. module:: GetType                                           |
|                                                               |
| **GetType()**                                                 |
|     Retourne le type de la frontière:                         |
|                                                               |
|         * 0: discrete                                         |
|         * 1: cylindre                                         |
|         * 2: sphere                                           |
|         * 3: cône défini par un axe et un angle               |
|         * 4: cône défini par deux rayons                      |
+---------------------------------------------------------------+
| .. module:: GetCoords                                         |
|                                                               |
| **GetCoords()**                                               |
|     Retourne un tableau contenant les coordinates de la       |
|     frontière dans l'ordre d'entrée dans le CreateBoundaryXXXX|
|     associé                                                   |
+---------------------------------------------------------------+
| .. module:: Delete                                            |
|                                                               |
| **Delete()**                                                  |
|     Detruit la frontière.                                     |
|     Pour une frontière discrete, le fichier du maillage       |
|     associé est conservé.                                     |
|                                                               |
|     Retourne un entier:                                       |
|         * 0: destruction réussie                              |
|         * autre valeur: problème                              |
+---------------------------------------------------------------+


Exemple
"""""""
Création d'une frontière discrete, d'une frontière sphèrique, puis d'une frontière cylindrique: ::

    inter = homard.CreateBoundaryDi("INTERSECTION", 'PIQUAGE', dircase+'/tutorial_4.fr.med')
    fron_1 = homard.CreateBoundarySphere("FRON_1", 12.3, 3.4, .56, 6.5)
    fron_2 = homard.CreateBoundaryCylinder('CYL_1', 0.0, 25., -25., 25., 50., 75., 100.)


Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_boundary_en`
