.. _tui_create_hypothese:

The hypothesis
##############

.. index:: single: iteration
.. index:: single: hypothesis
.. index:: single: zone

The variables are described in :ref:`gui_create_hypothese`.

Methods of the class homard
***************************

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateHypothesis                                  |
|                                                               |
| **CreateHypothesis(hypo_name)**                               |
|     Returns an instance of the class ``hypothese``            |
|                                                               |
|     - ``hypo_name``: the name of the hypothesis               |
+---------------------------------------------------------------+
| .. module:: GetHypothesis                                     |
|                                                               |
| **GetHypothesis(hypo_name)**                                  |
|     Returns an instance of the class ``hypothese``            |
|     known by its name                                         |
|                                                               |
|     - ``hypo_name``: the name of the hypothesis               |
+---------------------------------------------------------------+
| .. module:: GetAllHypothesesName                              |
|                                                               |
| **GetAllHypothesesName()**                                    |
|     Returns the liste of the name of all the existing         |
|     hypotheses                                                |
|                                                               |
+---------------------------------------------------------------+

Methods of the class hypothese
******************************

General methods
===============

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Returns the name of the hypothesis                        |
+---------------------------------------------------------------+
| .. module:: SetAdapRefinUnRef                                 |
|                                                               |
| **SetAdapRefinUnRef(Adap, Refin, UnRef)**                     |
|     Gives the type of adaptation to the hypothesis            |
|                                                               |
|     - ``Adap``: integer that defines the type of adaptation   |
|                                                               |
|         * -1: uniform                                         |
|         * 0: by zones                                         |
|         * 1: by a field                                       |
|                                                               |
|     - ``Refin``: integer that informs if the refinement is    |
|       active or not                                           |
|                                                               |
|         * 0: unactive                                         |
|         * 1: active                                           |
|                                                               |
|     - ``UnRef``: integer that informs if the refinement is    |
|       active or not                                           |
|                                                               |
|         * 0: unactive                                         |
|         * 1: active                                           |
|                                                               |
+---------------------------------------------------------------+
| .. module:: GetAdapType                                       |
|                                                               |
| **GetAdapType()**                                             |
|     Returns the type of the adaptation                        |
+---------------------------------------------------------------+
| .. module:: GetRefinType                                      |
|                                                               |
| **GetRefinType()**                                            |
|     Returns the type of the refinement                        |
+---------------------------------------------------------------+
| .. module:: GetUnRefType                                      |
|                                                               |
| **GetUnRefType()**                                            |
|     Returns the type of the unrefinement                      |
+---------------------------------------------------------------+
| .. module:: Delete                                            |
|                                                               |
| **Delete()**                                                  |
|     Deletes the hypothesis                                    |
|                                                               |
|     Returns an integer:                                       |
|         * 0: the destruction is done                          |
|         * other value: problem                                |
+---------------------------------------------------------------+

The field and the thresholds
============================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetField                                          |
|                                                               |
| **SetField(field_name)**                                      |
|     Gives the name of a field to the hypothesis               |
|                                                               |
|     - ``field_name``: the name of the field                   |
+---------------------------------------------------------------+
| .. module:: GetFieldName                                      |
|                                                               |
| **GetFieldName()**                                            |
|     Returns the name of the field                             |
+---------------------------------------------------------------+
| .. module:: SetUseField                                       |
|                                                               |
| **SetUseField(use_field)**                                    |
|     Gives the usage of the field for the hypothesis           |
|                                                               |
|     - ``use_field``: integer that defines how the field is    |
|       used                                                    |
|                                                               |
|        * 0: value by element (default)                        |
|        * 1: jump between an element and its neighbours        |
+---------------------------------------------------------------+
| .. module:: SetRefinThr                                       |
|                                                               |
| **SetRefinThr(type_thres, threshold)**                        |
|     Defines the thresholds for the refinement                 |
|                                                               |
|     - ``type_thres``: integer that defines the type of the    |
|       threshold for the refinement                            |
|                                                               |
|        * 1: absolute value                                    |
|        * 2: relative value in %                               |
|        * 3: ratio of elements in %                            |
|        * 4: mean + n times the standard deviation             |
|                                                               |
|     - ``threshold``: numerical value that defines the         |
|       threshold                                               |
+---------------------------------------------------------------+
| .. module:: GetRefinThrType                                   |
|                                                               |
| **GetRefinThrType()**                                         |
|     Returns the type of the threshold for the refinement      |
+---------------------------------------------------------------+
| .. module:: SetUnRefThr                                       |
|                                                               |
| **SetUnRefThr(type_thres, threshold)**                        |
|     Defines the thresholds for the unrefinement               |
|                                                               |
|     - ``type_thres``: integer that defines the type of the    |
|       threshold for the unrefinement                          |
|                                                               |
|        * 1: absolute value                                    |
|        * 2: relative value in %                               |
|        * 3: ratio of elements in %                            |
|        * 4: mean - n times the standard deviation             |
|                                                               |
|     - ``threshold``: numerical value that defines the         |
|       threshold                                               |
+---------------------------------------------------------------+
| .. module:: GetUnRefThrType                                   |
|                                                               |
| **GetUnRefThrType()**                                         |
|     Returns the type of the threshold for the unrefinement    |
+---------------------------------------------------------------+


The components of the field
===========================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddComp                                           |
|                                                               |
| **AddComp(comp_name)**                                        |
|     Add a component of the field                              |
|                                                               |
|     - ``comp_name``: name of a component to take into account |
+---------------------------------------------------------------+
| .. module:: SetUseComp                                        |
|                                                               |
| **SetUseComp(use_comp)**                                      |
|     Defines hom to use the components                         |
|                                                               |
|     - ``use_comp``: integer that defines how to use the       |
|       components                                              |
|                                                               |
|        * 0: L2 norm (default)                                 |
|        * 1: infinite norm                                     |
|        * 2: relative value, if only one component             |
+---------------------------------------------------------------+
| .. module:: GetListComp                                       |
|                                                               |
| **GetListComp()**                                             |
|     Returns the list of the used components                   |
+---------------------------------------------------------------+


The zones
=========

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddZone                                           |
|                                                               |
| **AddZone(zone_name, type_use)**                              |
|                                                               |
|     - ``zone_name``: the name of the zone to add              |
|     - ``type_use``: integer that defines how to use the zone  |
|                                                               |
|         * 1: refinement                                       |
|         * -1: unrefinement                                    |
+---------------------------------------------------------------+


The filtering by the groups
===========================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddGroup                                          |
|                                                               |
| **AddGroup(group_name)**                                      |
|     Add a group to the filtering                              |
|                                                               |
|     - ``group_name``: name of the group to take into account  |
+---------------------------------------------------------------+
| .. module:: GetGroups                                         |
|                                                               |
| **GetGroups()**                                               |
|     Returns the mist of the groups that are used in the       |
|     filtering                                                 |
+---------------------------------------------------------------+

Advanced options
================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetNivMax                                         |
|                                                               |
| **SetNivMax(nivmax)**                                         |
|     Defines the maximum level for the refinement              |
|                                                               |
|     - ``nivmax``: level of refinement that must not be        |
|       exceeded                                                |
+---------------------------------------------------------------+
| .. module:: GetNivMax                                         |
|                                                               |
| **GetNivMax()**                                               |
|     Returns the maximum level for the refinement              |
+---------------------------------------------------------------+
| .. module:: SetDiamMin                                        |
|                                                               |
| **SetDiamMin(diammin)**                                       |
|     Defines the minimum diameter of the future elements       |
|                                                               |
|     - ``diammin``: minimum diameter for an element            |
+---------------------------------------------------------------+
| .. module:: GetDiamMin                                        |
|                                                               |
| **GetDiamMin()**                                              |
|     Returns the minimum diameter of the future elements       |
+---------------------------------------------------------------+
| .. module:: SetAdapInit                                       |
|                                                               |
| **SetAdapInit(option)**                                       |
|     Defines the treatment of the elements where the field that|
|     governs the adaptation is not defined                     |
|                                                               |
|     - ``option``: integer as follows:                         |
|                                                               |
|         *  0: no effect (default)                             |
|         *  1: the elements without field are refined          |
|         * -1: the elements without field are unrefined        |
+---------------------------------------------------------------+
| .. module:: GetAdapInit                                       |
|                                                               |
| **GetAdapInit()**                                             |
|     Returns the treatment of the elements where the field that|
|     governs the adaptation is not defined                     |
+---------------------------------------------------------------+
| .. module:: SetLevelOutput                                    |
|                                                               |
| **SetLevelOutput(option)**                                    |
|     Acts if the level of refinement is returned as a field in |
|     the output MED file                                       |
|                                                               |
|     - ``option``: integer as follows:                         |
|                                                               |
|         *  0: no effect (default)                             |
|         *  1: the field is produced                           |
+---------------------------------------------------------------+
| .. module:: GetLevelOutput                                    |
|                                                               |
| **GetLevelOutput()**                                          |
|     Returns the choice for the output of the level of         |
|     refinement                                                |
+---------------------------------------------------------------+


Example
*******
The creation of the object hypo_1 is done as follows:
::

    hypo_1 = homard.CreateHypothesis("HypoField")
    hypo_1.SetAdapRefinUnRef(1, 1, 0)
    hypo_1.SetField("INDICATEUR")
    hypo_1.AddComp("INDX")
    hypo_1.AddComp("INDZ")
    hypo_1.SetRefinThr(1, 80.)


Similar graphical input
***********************
Look at :ref:`gui_create_hypothese`

.. warning::
  With the graphical input mode, if an hypothesis is edited and if one of the characteristic is modified, the value of the threshold for the refinement for example, all the iterations that were computed with this hypothesis are unvalidated. In python mode, that is not true: the iterations stay as they are.
