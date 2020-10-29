# Copyright (C) 2016-2020  CEA/DEN, EDF R&D
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
# Compilation de ES_HOMARD

SET(ES_HOMARD_SOURCES
    ./esece0.F
    ./esece1.F
    ./esece2.F
    ./esecen.F
    ./esecf0.F
    ./esecfd.F
    ./esecfe.F
    ./esecfs.F
    ./esecig.F
    ./esecn1.F
    ./esecno.F
    ./esecs1.F
    ./esecs2.F
    ./esecs3.F
    ./esecs4.F
    ./esecs5.F
    ./esecsu.F
    ./esemh0.F
    ./esemh1.F
    ./esemh2.F
    ./esemho.F
    ./esle01.F
    ./esle02.F
    ./esle03.F
    ./eslee0.F
    ./eslee1.F
    ./eslee2.F
    ./esleen.F
    ./eslefe.F
    ./eslen1.F
    ./esleno.F
    ./eslmh1.F
    ./eslmh2.F
    ./eslmh3.F
    ./eslmh4.F
    ./eslmh5.F
    ./eslmh6.F
    ./eslmh7.F
    ./eslmho.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/ES_HOMARD ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (ES_HOMARD ${ES_HOMARD_SOURCES})

INSTALL(TARGETS ES_HOMARD EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
