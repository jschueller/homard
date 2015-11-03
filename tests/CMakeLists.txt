# Copyright (C) 2007-2015  CEA/DEN, EDF R&D
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

SET(HOMARD_TEST_FILES
  test_util.py
  test_1.pdf
  test_1.en.pdf
  test_1.py
  test_1.00.med
  test_1.01.med
  test_1.02.med
  test_1.apad.03.bilan
  test_2.pdf
  test_2.en.pdf
  test_2.py
  test_2.00.med
  test_2.fr.med
  test_2.apad.03.bilan
  test_3.pdf
  test_3.en.pdf
  test_3.py
  test_3.00.med
  test_3.fr.med
  test_3.apad.02.bilan
  test_4.pdf
  test_4.en.pdf
  test_4.py
  test_4.apad.03.bilan
  test_11.py
  test_11.apad.03.bilan
  test_12.py
  test_12.apad.02.bilan
  test_13.py
  test_13.apad.02.bilan
  test_14.py
  test_14.apad.03.bilan
  test_15.py
  test_15.apad.02.bilan
)

INSTALL(FILES ${HOMARD_TEST_FILES} DESTINATION ${SALOME_HOMARD_INSTALL_RES_DATA})
