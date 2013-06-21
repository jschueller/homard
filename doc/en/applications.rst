.. _gui_applications:

.. index:: single: application
.. index:: single: illustration

Applications
============
Some applications of the mesh adaptation are listed below.

Some illustrations of adapted meshes
""""""""""""""""""""""""""""""""""""

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

Non linear mechanical calculation
"""""""""""""""""""""""""""""""""

The piece is locked on its left side. This upper right side is pressed, with a time depending charge. The genuine border of the piece is round. In the initial mesh, this border is roughly described. During the adaptation, when mesh is refined near the border, the new nodes are located on to the genuine border. Therefore, the geometry is followed as closed as possible.


This computation is made with Code_Aster. The law is Von Mises. The time evolution lasts 480 s, with a 3 s time step. The calculation is splitted into 32 calculations. The calculation #k is from t=0 to t=15*k s. At this final instant, the mesh is adapted. Then, the next computation begins from scratch. This strategy produces a adapted mesh for all the instants of the evolution and is free from interpolation.

.. image:: ../images/appli_01.gif
   :align: center

