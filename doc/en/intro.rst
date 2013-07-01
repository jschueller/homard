.. _intro:

Introduction
############

General presentation
********************
Le logiciel HOMARD est destiné à adapter les maillages dans le cadre des codes de calculs par éléments ou volumes finis. Ce logiciel, réalisé par EDF R&D, procède par raffinement et déraffinement des maillages bidimensionnels ou tridimensionnels. Il est conçu pour être utilisé indépendamment du code de calcul auquel il est couplé.

Raffiner le maillage signifie découper des mailles désignées selon des indications founies par l'utilisateur. Déraffiner le maillage signifie revenir en arrière sur des découpages précédemment réalisés : ainsi, en aucun cas HOMARD ne peut simplifier un maillage existant qui aura été créé trop fin. Le déraffinement prend toute son importance dans les calculs quand la zone d'intérêt se déplace au cours du calcul pour ne plus tenir compte de raffinements précédemment réalisés et qui deviennent inutiles. On en trouvera une illustration au bas de cette page.

HOMARD sait traiter des maillages en 2 ou 3 dimensions et comportant les mailles suivantes :
   - mesh-points
   - segments
   - triangles
   - quadrangles
   - tetrahedra
   - hexahaedra
   - prisms

Ces mailles peuvent être présentes simultanément. Par exemple, HOMARD saura adapter un maillage comportant des triangles et des quadrangles.
Les noeuds acceptés sont évidemment les noeuds qui sont les sommets des mailles, ce qui correspond à la description classique « en degré 1 » . Si les éléments sont décrits « en degré 2 », les noeuds complémentaires sont gérés. En revanche, il ne peut pas y asee cohabitation de mailles décrites en degré 1 et d'autres décrites en degré 2. Enfin, HOMARD sait prendre en compte des noeuds isolés, qui n'appartiendraient à aucune définition de mailles : ils ressortiront tels quels du processus d'adaptation.

Le cas des pyramides est à part. Pour un maillage comportant des hexaèdres ou des prismes, la mise en conformité du maillage issu du raffinement crée des pyramides pour assurer la liaison entre deux régions de niveaux de raffinement différents. Ces pyramides sont gérées comme toutes les mailles de transition et ne sont pas redécoupées par la suite. En revanche, si le maillage initial contient des pyramides, HOMARD ne saura pas l'adapter et émettra un message d'erreur. Dans certains cas particuliers, on pourra néanmoins traiter un tel maillage, comme il est décrit dans la rubrique 'Options avancées' de :ref:`gui_create_case`).

Plusieurs motivations apparaissent pour adapter un maillage :

  - on veut simplifier la réalisation du maillage d'une géométrie complexe : on part d'un maillage grossier et on confie à un processus automatique la charge de le raffiner.
  - on veut s'assurer de la convergence de la solution numérique : plutôt que de réaliser à la main des maillages de plus en plus fins, on laisse le logiciel chercher lui-même les endroits où il faudrait affiner le maillage pour augmenter la précision du résultat.
  - les conditions du calcul changent au cours de son déroulement : les zones qui doivent être maillées finement se déplacent. Si on maille fin partout dès le début, le maillage est trop gros. En adaptant au fur et à mesure, le maillage ne sera fin qu'aux endroits nécessaires : sa taille sera réduite et la qualité de la solution sera bonne.

Dans tous les cas, le principe de l'adaptation de maillage reste le même. Sur le maillage de départ, on réalise le calcul standard. Avec une analyse de la solution numérique obtenue, on estime l'erreur qui a été commise par rapport à la solution réelle. Cette estimation se représente par une valeur d'indicateur d'erreur dans chaque maille du calcul. A partir de là, on applique le principe suivant : les mailles où l'indicateur d'erreur est fort devraient être plus petites et, réciproquement, les mailles où l'indicateur d'erreur est faible pourraient être plus grandes. Avec cette information, on alimente HOMARD qui va modifier le maillage en conséquence. Sur le nouveau maillage, on recommencera alors le calcul.


Broadly speaking, an iteration for meshing adaptation is as shown on the figure below. The finite element software calculates the numerical solution on meshing Mk, then, from that, deduces the values for the error indicator over the whole meshing. Based on the knowledge of meshing #k and indicator #k, HOMARD generates a new meshing #k+1.

.. image:: images/intro_1.png
   :align: center

The complete chain starts from the initial meshing, then incorporates successive links (calculation of indicator / adaptation).

.. image:: ../images/intro_2.png
   :align: center

Some variations may exist. If no error indicator is available, another filed can be used to drive the adaptation. A stress field in mechanics can be used: the refinement of the elements where the stress is high is often efficient to improve the quality of the results. It is also possible to drive the adaptation according the variation of a filed from one element to its neighbours. The refinement can be filtered by zones or groups of elements.

.. note::
  For a extensive description of HOMARD, see :download:`Description générale de HOMARD <../files/HOMARD_0.pdf>`.

.. note::
  To quote HOMARD, please refer to:

  G. Nicolas and T. Fouquet, Adaptive Mesh Refinement for Conformal Hexahedral Meshes, "*Finite Elements in Analysis and Design*", Vol. 67, pp. 1-12, 2013, doi:10.1016/j.finel.2012.11.008


  `Available here <http://dx.doi.org/10.1016/j.finel.2012.11.008>`_

Methods for splitting the elements
**********************************
.. index:: single: splitting
.. index:: single: conformity

All in all, the process of meshing adaptation by splitting element is a two-tier process. First, all element specified by the error indicator are split. The resulting meshing is uncorrect : nodes are pending at the junction between areas to be refined, and an area to be retained. The second stage aims at solving all of these conformity problems.

There are different splitting methods for the two phases. During the first phase, all of the element are split in the same manner ; this is the so-called standard splitting. During the second phase, some of the meshing conformity conflicts in the junction area are settled by the same standard splitting of element, while others are settled by special splitting.

The various splitting modes have been choosen to preserve the mesh quality, all along the adaptive process.

Standard splitting
==================
Standard element splitting is carried out with a view to restricting the number of cases. Thus, edges are split into two equal sections.

To split a triangle, the three edges are split into two sections each, thus producing four similar triangles. They retain the same quality.

.. image:: ../images/dec_tria_1.gif
   :align: center
   :alt: Découpage standard d'un triangle
   :width: 399
   :height: 88

To split a quadrangle, the four edges are split into two sections each, thus producing four non-similar quadrangles with different quality.

.. image:: ../images/dec_quad_1.png
   :align: center
   :alt: Découpage standard d'un quadrangle
   :width: 399

Tetrahedrons are split in eight. First, each of the triangular faces is split into 4 similar triangular faces.

.. image:: ../images/dec_tetr_1.gif
   :align: center
   :alt: Découpage standard d'un tétraèdre - 1
   :width: 328
   :height: 115

Face splitting produces four tetrahedrons at the angles of the initial tetrahedron. It should be noted that the four new tetrahedrons are homothetic to the initial tetrahedron. Therefore, they retain the same qualities.

.. image:: ../images/dec_tetr_2.gif
   :align: center
   :alt: Découpage standard d'un tétraèdre - 2
   :width: 201
   :height: 159

At the core of the tetrahedron, there remains a block shaped like two pyramids joined at their bases. An edge is generated using one of the three possible diagonals, then the four faces containing the edge, and two external edges.

.. image:: ../images/dec_tetr_3.gif
   :align: center
   :alt: Découpage standard d'un tétraèdre - 3
   :width: 244
   :height: 74

This, in turn, creates 4 new tetrahedrons. It should be noted that they are similar two by two but that they can never be similar to the initial tetrahedron. They can therefore never have the same quality as the initial tetrahedron. However, different results are obtained, depending on the diagonal selected for splitting the internal pyramidal block. Where quality is concerned, it is always best to select the smallest of the three possible diagonals.

.. image:: ../images/dec_tetr_4.gif
   :align: center
   :alt: Découpage standard d'un tétraèdre - 4
   :width: 229
   :height: 116

Hexaedrons are split in eight. Each of the quadrangular faces is split into 4 quadrangular faces. Edges are created connecting each centre of opposite faces. This generates a new point located at the centre of the hexaedron.

.. image:: ../images/dec_hex.png
   :align: center
   :alt: Découpage standard d'un hexaèdre
   :scale: 70

Pentaedrons are split in eight. Each of the quadrangular faces is split into 4 quadrangular faces and the two triangles are split into 4. Edges are created connecting each centre of quadrangular faces. Those 3 edges create 4 triangles at the centre of the pentaedron. Six quandrangular faces are created to complete the construction of the height pentaedrons.

.. image:: ../images/dec.pent.png
   :align: center
   :alt: Découpage standard d'un pentaèdre
   :scale: 20

Splitting for the conformity
============================

Splitting for conformity is applicable to the elements at the interface between two different levels of refinement. Such splitting may produce element of lower quality compared to the initial element, and in the general algorithm, one sees how this drawback is reckoned with to reduce its consequences.

For triangles, one of the three edges is split in two. Its middle is joined to the opposite vertex to form two additional triangles.

.. image:: ../images/dec_tria_2.gif
   :align: center
   :alt: Découpage de conformité d'un triangle
   :width: 399
   :height: 88

For quadrangles, one of the four edges is split in two. Its middle is joined to the opposite vertex to form three triangles. The mesh obtained is then mixed.

.. image:: ../images/dec_quad_2.png
   :align: center
   :alt: Découpage de conformité d'un quadrangle
   :width: 399

For a tetrahedron with three split edges, this is possible only if the edges are concurrent. Therefore, one of the four faces is split in four. The middles of the split edges are joined to the opposite vertexes. The three other faces are thus split in two, and four tetrahedrons are created.

.. image:: ../images/dec_tetr_5.gif
   :align: center
   :alt: Découpage de conformité d'un tétraèdre - 1
   :width: 116
   :height: 116

For a tetrahedron with two split edges, this is possible only if the edges are opposite. All the middles of these edges are joined to the other apexes, as well as the edge middles. The four faces are split in two, and four tetrahedrons are created.

.. image:: ../images/dec_tetr_6.gif
   :align: center
   :alt: Découpage de conformité d'un tétraèdre - 2
   :width: 116
   :height: 116

For a tetrahedron with one split edge, the middle of the split edge is joined to the opposite apex, and two tetrahedrons are created.

.. image:: ../images/dec_tetr_6.gif
   :align: center
   :alt: Découpage de conformité d'un tétraèdre - 3
   :width: 116
   :height: 116

The conformal strategy for the hexaedrons is based on tetraedrons and pyramids. The situation depends on the number of non conformities.

For an hexaedron with one face cut, we create 4 edges, 4 tetraedrons and 5 pyramids.

.. image:: ../images/hexaface.png
   :align: center
   :alt: Découpage de conformité d'un hexaèdre - 1 face
   :width: 384
   :height: 101

For an hexaedron with only one edge cut, we create deux internal edges and four pyramids.

.. image:: ../images/hexa1arete.png
   :align: center
   :alt: Découpage de conformité d'un hexaèdre - 1 arête
   :width: 384
   :height: 101

For an hexaedron with two edges cut, we create one central point 10 edges, 12 tetraedrons and 2 pyramids.

.. image:: ../images/hexa2aretes.png
   :align: center
   :alt: Découpage de conformité d'un hexaèdre - 2 arêtes
   :width: 384
   :height: 101

For an hexaedron with three edges cut, we create one central point, 11 edges and 18 tetraedrons.

.. image:: ../images/hexa3aretes.png
   :align: center
   :alt: Découpage de conformité d'un hexaèdre - 3 arêtes
   :width: 384
   :height: 101



Algorithm
*********
.. index:: single: algorithm

The strategy adopted for the algorithm in HOMARD consists in forcing splitting in four for all faces with two hanging nodes. Eventually, only the faces with non conformity points are faces where one and only edge is split. The simplest possible solution is thus used for conformity as seen before. The latter stage of conformity introduces element of modified quality compared to that of the element it originated from. This drawback remains under control as we have chosen to grant a temporary status to the conformity element: they exist to produce a meshing acceptable by the calculation softwares, but they disappear if they are required to be further split. As a consequence, quality loss does not propagate along iterations of meshing adaptation, and remains restricted in value as well as in number of element concerned.

The algorithm is:

   * Transfer of refining or coarsening indications over element into decisions to split or group edges, triangles and quadrangles.
   * Removal of temporary compliance element.
   * By considering all triangles and quadrangles from the lowest splitting level to the highest splitting level, conflict solving on coarsening using the basic rules.
   * By considering all triangles and quadrangles from the lowest splitting level to the highest splitting level, conflict solving on refining using the basic rules.
   * Effective generation of new meshing : standard splitting, compliance tracking.


Some illustrations of adapted meshes
************************************
.. index:: single: illustration

Some examples of use case can be found into :ref:`applications` .

+---------------------------------------------------------------+
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_3.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_4.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_5.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_6.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_7.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_8.gif                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+

