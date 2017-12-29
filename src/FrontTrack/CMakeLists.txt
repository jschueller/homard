# --- options ---
# additional include directories
INCLUDE_DIRECTORIES(
  ${CAS_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${GEOM_INCLUDE_DIRS}
  ${MEDFILE_INCLUDE_DIRS}
  ${MEDCOUPLING_INCLUDE_DIRS}
  ${TBB_INCLUDE_DIRS}
)

# additional preprocessor / compiler flags
ADD_DEFINITIONS(
  ${CAS_DEFINITIONS}
  ${BOOST_DEFINITIONS}
)

IF(FRONTTRACK_USE_TBB)
  SET(TBB_LIBS ${TBB_LIBRARIES})
ENDIF(FRONTTRACK_USE_TBB)

# libraries to link to
SET(_link_LIBRARIES
  ${CAS_TKShHealing}
  ${CAS_TKernel}
  ${CAS_TKBRep}
  ${CAS_TKG3d}
  ${CAS_TKTopAlgo}
  ${CAS_TKGeomBase}
  ${CAS_TKGeomAlgo}
  ${GEOM_XAO}
  ${MEDCoupling_medloader}
  ${TBB_LIBS}
  ${Boost_LIBRARIES}
)

# --- headers ---

# header files
SET(FRONTTRACK_HEADERS
  FrontTrack.hxx
)

# --- sources ---

# sources / static
SET(FRONTTRACK_SOURCES
  FrontTrack.cxx
  FrontTrack_NodeGroups.cxx
  FrontTrack_NodesOnGeom.cxx
  FrontTrack_Projector.cxx
  FrontTrack_Utils.cxx
)

# --- rules ---

ADD_LIBRARY(FrontTrack ${FRONTTRACK_SOURCES})
TARGET_LINK_LIBRARIES(FrontTrack ${_link_LIBRARIES} )
INSTALL(TARGETS FrontTrack EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})

INSTALL(FILES ${FRONTTRACK_HEADERS} DESTINATION ${SALOME_INSTALL_HEADERS})
