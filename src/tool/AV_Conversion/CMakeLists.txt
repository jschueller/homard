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
# Compilation de AV_Conversion

SET(AV_Conversion_SOURCES
    ./vccfam.F
    ./vccfca.F
    ./vccfcf.F
    ./vccfnc.F
    ./vcequ1.F
    ./vcequ2.F
    ./vcequ3.F
    ./vcequ4.F
    ./vcequ5.F
    ./vcequ6.F
    ./vcequ7.F
    ./vcequa.F
    ./vcequi.F
    ./vcequn.F
    ./vcfia0.F
    ./vcfia1.F
    ./vcfia2.F
    ./vcfia3.F
    ./vcfia4.F
    ./vcfiad.F
    ./vcind0.F
    ./vcind1.F
    ./vcind2.F
    ./vcind3.F
    ./vcindi.F
    ./vcinr1.F
    ./vcinr2.F
    ./vcinrr.F
    ./vcmaco.F
    ./vcmafa.F
    ./vcmaig.F
    ./vcmail.F
    ./vcmar0.F
    ./vcmare.F
    ./vcme21.F
    ./vcme22.F
    ./vcme23.F
    ./vcme24.F
    ./vcme25.F
    ./vcme26.F
    ./vcme27.F
    ./vcme28.F
    ./vcme29.F
    ./vcme30.F
    ./vcme31.F
    ./vcme32.F
    ./vcmex0.F
    ./vcmex1.F
    ./vcmex2.F
    ./vcmexa.F
    ./vcmexb.F
    ./vcmexd.F
    ./vcmext.F
    ./vcmfac.F
    ./vcmmen.F
    ./vcmmpo.F
    ./vcmnc1.F
    ./vcmnc2.F
    ./vcmnc3.F
    ./vcmnc4.F
    ./vcmnco.F
    ./vcmnoe.F
    ./vcmre0.F
    ./vcmren.F
    ./vcms20.F
    ./vcms21.F
    ./vcms22.F
    ./vcms2d.F
    ./vcmver.F
    ./vcori1.F
    ./vcori2.F
    ./vcorie.F
    ./vcsfal.F
    ./vcsfas.F
    ./vcsfin.F
    ./vcsfl0.F
    ./vcsflg.F
    ./vcsfli.F
    ./vcsfll.F
    ./vcvar1.F
    ./vcvar2.F
    ./vcvos1.F
    ./vcvos2.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/AV_Conversion ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (AV_Conversion ${AV_Conversion_SOURCES})

INSTALL(TARGETS AV_Conversion EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
