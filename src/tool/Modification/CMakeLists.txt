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
# Compilation de Modification

SET(Modification_SOURCES
    ./mmag10.F
    ./mmag11.F
    ./mmag12.F
    ./mmag13.F
    ./mmag30.F
    ./mmag31.F
    ./mmag32.F
    ./mmag33.F
    ./mmag34.F
    ./mmag35.F
    ./mmag36.F
    ./mmag40.F
    ./mmag41.F
    ./mmag42.F
    ./mmag43.F
    ./mmag91.F
    ./mmag92.F
    ./mmag93.F
    ./mmag94.F
    ./mmagco.F
    ./mmagf0.F
    ./mmagf1.F
    ./mmagr0.F
    ./mmagr2.F
    ./mmagr4.F
    ./mmagr5.F
    ./mmagr6.F
    ./mmagre.F
    ./mmagve.F
    ./mmcnp2.F
    ./mmdeg0.F
    ./mmdegr.F
    ./mmelde.F
    ./mmmodi.F
    ./mmsn21.F
    ./mmsn22.F
    ./mmsnp2.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/Modification ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (Modification ${Modification_SOURCES})

INSTALL(TARGETS Modification EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
