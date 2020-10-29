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
# Compilation de Dependance_Machine

SET(Dependance_Machine_SOURCES
    ./dmabor.F
    ./dmalme.F
    ./dmcpch.F
    ./dmflsh.F
    ./dmftmp.F
    ./dmindf.F
    ./dmjohe.F
    ./dmlibe.F
    ./dmloci.F
    ./dmlocr.F
    ./dmlocs.F
    ./dmmach.F
    ./dmnfcv.F
    ./dmoubs.F
    ./dmoufs.F
    ./dmprma.F
    ./dmralo.F
    ./dmsepf.F
    ./dmsize.F
    ./dmtemp.F
    ./dmunit.F
    ./dmvaen.F
    ./dmze10.F
    ./dmzero.F
    ./dmaboc.c
    ./dmalmc.c
    ./dmdate.c
    ./dmflsc.c
    ./dmlibc.c
    ./dmloca.c
    ./dmmacc.c
    ./dmprmc.c
    ./dmralc.c
    ./dmsepc.c
    ./dmsizc.c
    ./dmtemc.c
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/Dependance_Machine ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (Dependance_Machine ${Dependance_Machine_SOURCES})

INSTALL(TARGETS Dependance_Machine EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
