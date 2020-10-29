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
# Compilation de AP_Conversion

SET(AP_Conversion_SOURCES
    ./pccac1.F
    ./pccac2.F
    ./pccafo.F
    ./pccapf.F
    ./pccapg.F
    ./pccapr.F
    ./pcceq1.F
    ./pcceq2.F
    ./pcceq3.F
    ./pcceq4.F
    ./pcehe1.F
    ./pcepe1.F
    ./pcequ1.F
    ./pcequ2.F
    ./pcequ3.F
    ./pcequ4.F
    ./pcete1.F
    ./pcetr1.F
    ./pcetr2.F
    ./pcetr3.F
    ./pcetr4.F
    ./pcfaa1.F
    ./pcfaa2.F
    ./pcfaa3.F
    ./pcfaat.F
    ./pcfor1.F
    ./pcfor2.F
    ./pcfore.F
    ./pcma21.F
    ./pcma22.F
    ./pcma23.F
    ./pcmaa0.F
    ./pcmaar.F
    ./pcmac1.F
    ./pcmaco.F
    ./pcmafa.F
    ./pcmahe.F
    ./pcmaig.F
    ./pcmail.F
    ./pcmamp.F
    ./pcmanc.F
    ./pcmano.F
    ./pcmape.F
    ./pcmapy.F
    ./pcmaq0.F
    ./pcmaqu.F
    ./pcmar0.F
    ./pcmar1.F
    ./pcmar2.F
    ./pcmar3.F
    ./pcmarc.F
    ./pcmat0.F
    ./pcmate.F
    ./pcmatr.F
    ./pcmex0.F
    ./pcmex1.F
    ./pcmex2.F
    ./pcmex3.F
    ./pcmext.F
    ./pcmmen.F
    ./pcs0he.F
    ./pcs0pe.F
    ./pcs0qu.F
    ./pcs0te.F
    ./pcs0tr.F
    ./pcs1ar.F
    ./pcs1he.F
    ./pcs1pe.F
    ./pcs1qu.F
    ./pcs2ar.F
    ./pcs2h1.F
    ./pcs2h2.F
    ./pcs2h3.F
    ./pcs2h4.F
    ./pcs2h5.F
    ./pcs2he.F
    ./pcs2p1.F
    ./pcs2p2.F
    ./pcs2p3.F
    ./pcs2p4.F
    ./pcs2p5.F
    ./pcs2p6.F
    ./pcs2pe.F
    ./pcs2qu.F
    ./pcs2te.F
    ./pcs2tr.F
    ./pcs3tr.F
    ./pcsar0.F
    ./pcsar1.F
    ./pcseh0.F
    ./pcseh1.F
    ./pcseh8.F
    ./pcseh9.F
    ./pcsehy.F
    ./pcsehz.F
    ./pcsep0.F
    ./pcsep1.F
    ./pcsep8.F
    ./pcsep9.F
    ./pcsepy.F
    ./pcsepz.F
    ./pcseq0.F
    ./pcseq1.F
    ./pcseq2.F
    ./pcseq3.F
    ./pcseq4.F
    ./pcset0.F
    ./pcset2.F
    ./pcset4.F
    ./pcset8.F
    ./pcshe0.F
    ./pcsi00.F
    ./pcsiar.F
    ./pcsihe.F
    ./pcsipe.F
    ./pcsiqu.F
    ./pcsite.F
    ./pcsitr.F
    ./pcsmar.F
    ./pcsoar.F
    ./pcsohe.F
    ./pcsolu.F
    ./pcsono.F
    ./pcsope.F
    ./pcsoqu.F
    ./pcsote.F
    ./pcsotr.F
    ./pcsovr.F
    ./pcspe0.F
    ./pcsprn.F
    ./pcspt0.F
    ./pcspt2.F
    ./pcspt4.F
    ./pcspt8.F
    ./pcsptd.F
    ./pcsptq.F
    ./pcsptz.F
    ./pcsqu0.F
    ./pcsqug.F
    ./pcsrc0.F
    ./pcsrho.F
    ./pcste0.F
    ./pcsteg.F
    ./pcstr0.F
    ./pcstrg.F
    )

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src/tool/AP_Conversion ../Includes_Generaux)

SET ( CMAKE_Fortran_FLAGS "-ffixed-line-length-0 -fdefault-double-8 -fdefault-real-8 -fdefault-integer-8 -fimplicit-none -O2" )

ADD_LIBRARY (AP_Conversion ${AP_Conversion_SOURCES})

INSTALL(TARGETS AP_Conversion EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})
