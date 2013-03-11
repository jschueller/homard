.. _tui_create_case:

Le cas
======
.. index:: single: cas
.. index:: single: type de conformité
.. index:: single: maillage;initial

Les variables sont décrites dans :ref:`gui_create_case`.

Méthodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateCase                                        |
|                                                               |
| **CreateCase(case_name, mesh_name, mesh_file)**               |
|     Retourne une instance de la classe ``cas`` après sa       |
|     création                                                  |
|                                                               |
|     - ``case_name`` : le nom du cas                           |
|     - ``mesh_name`` : le nom du maillage initial              |
|     - ``mesh_file`` : le nom du fichier contenant ce maillage |
|                                                               |
| Par défaut :                                                  |
|                                                               |
|  * le répertoire des résultats est ``/tmp``                   |
|  * l'adaptation est conforme                                  |
+---------------------------------------------------------------+
| .. module:: GetCase                                           |
|                                                               |
| **GetCase(case_name)**                                        |
|     Retourne l'instance de la classe ``cas`` connue par       |
|     son nom                                                   |
|                                                               |
|     - ``case_name`` : le nom du cas                           |
+---------------------------------------------------------------+
| .. module:: GetAllCasesName                                   |
|                                                               |
| **GetAllCasesName()**                                         |
|     Retourne la liste des noms de tous les cas créés          |
|                                                               |
+---------------------------------------------------------------+


Méthodes de la classe cas
"""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom du cas                                    |
+---------------------------------------------------------------+
| .. module:: SetDirName                                        |
|                                                               |
| **SetDirName(dirname)**                                       |
|     Affecte le répertoire des résutats associé au cas         |
|                                                               |
|     - ``dirname`` : le nom du répertoire des résutats         |
+---------------------------------------------------------------+
| .. module:: GetDirName                                        |
|                                                               |
| **GetDirName()**                                              |
|     Retourne le nom du répertoire des résutats associé au cas |
+---------------------------------------------------------------+
| .. module:: SetConfType                                       |
|                                                               |
| **SetConfType(conf_type)**                                    |
|     Définit le mode de conformité associé au cas              |
|                                                               |
|     - ``conf_type`` : entier précisant le mode de conformité  |
|                                                               |
|         * 1 : conforme                                        |
|         * 2 : non conforme avec 1 noeud par maille            |
|         * 3 : non conforme avec 1 noeud par arete de maille   |
|         * 4 : non conforme quelconque                         |
+---------------------------------------------------------------+
| .. module:: GetConfType                                       |
|                                                               |
| **GetConfType()**                                             |
|     Retourne le type de conformité                            |
+---------------------------------------------------------------+
| .. module:: GetIter0                                          |
|                                                               |
| **GetIter0()**                                                |
|     Retourne l'itération 0, associée au maillage initial.     |
|     Cette itération est créée automatiquement par le module   |
|     HOMARD et est utilisée pour enchaîner les adaptations.    |
+---------------------------------------------------------------+
| .. module:: AddBoundaryGroup                                  |
|                                                               |
| **AddBoundaryGroup(boundary, group)**                         |
|     Ajoute une frontière à la définition du cas               |
|                                                               |
|     - ``boundary`` : nom d'une frontière courbe à suivre      |
|                                                               |
|     Pour une frontière discrète :                             |
|                                                               |
|     . si toutes les lignes courbes sont suivies, le second    |
|       argument est une chaîne vide.                           |
|     . si seulement certaines lignes courbes sont suivies,     |
|       ``group`` est le nom d'un groupe de segments à suivre.  |
|                                                               |
|     Pour une frontière analytique :                           |
|                                                               |
|     - ``group`` : nom d'un groupe de faces placées sur la     |
|       frontière                                               |
+---------------------------------------------------------------+
| .. index:: single: Delete                                     |
|                                                               |
| **Delete()**                                                  |
|     Detruit le cas et toutes les itérations associées ainsi   |
|     que tous les maillages produits. Le fichier du maillage   |
|     initial associé est conservé.                             |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : destruction réussie                             |
|         * autre valeur : problème                             |
+---------------------------------------------------------------+

Les options avancées
^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetPyram                                          |
|                                                               |
| **SetPyram(option)**                                          |
|     Définit le statut des pyramides pour le cas               |
|                                                               |
|     - ``option`` : entier précisant le statut des pyramides   |
|       éventuellement présentes dans le maillage initial       |
|                                                               |
|         * 0 : pyramides refusées (défaut)                     |
|         * 1 : pyramides autorisées                            |
+---------------------------------------------------------------+
| .. module:: GetPyram                                          |
|                                                               |
| **GetPyram()**                                                |
|     Retourne le statut accordé aux pyramides éventuellement   |
|     présentes dans le maillage initial                        |
+---------------------------------------------------------------+

Informations sur le maillage initial
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: MeshInfo                                          |
|                                                               |
| **MeshInfo(Qual, Diam, Conn, Tail, Inte)**                    |
|     Donne des informations sur le maillage. Pour chaque       |
|     option, le choix 0 correspond à ne rien faire, alors que  |
|     le choix 1 active l'option.                               |
|                                                               |
|     - ``Qual`` : qualité des mailles                          |
|     - ``Diam`` : diamètre des mailles                         |
|     - ``Conn`` : connexité du domaine ; en un seul morceau,   |
|       combien de trous, etc.                                  |
|     - ``Tail`` : tailles des constituants du domaine, groupe  |
|       par groupe                                              |
|     - ``Inte`` : interpénétration des mailles, par dimension  |
+---------------------------------------------------------------+


Exemple
"""""""
La création de l'objet case_1 se fait ainsi : ::

    case_name = "CAS_1"
    mesh_name = "MAILL"
    mesh_file = "/local00/Salome/Adapt/m0.med"
    case_1 = homard.CreateCase(case_name, mesh_name, mesh_file)
    dirname = "/local00/Salome/Adapt/resu"
    case_1.SetDirName(dirname)
    case_1.SetConfType(1)
    case_1.AddBoundaryGroup( 'intersection', '' )
    case_1.AddBoundaryGroup( 'cyl_1', 'T1_EXT' )
    case_1.AddBoundaryGroup( 'cyl_1', 'T2_EXT' )
    case_1.AddBoundaryGroup( 'cyl_2', 'T_INT' )



Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_case`


