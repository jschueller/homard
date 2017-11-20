
INCLUDE(${SWIG_USE_FILE})

ADD_DEFINITIONS(${PYTHON_DEFINITIONS})

SET_SOURCE_FILES_PROPERTIES(FrontTrack.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(FrontTrack.i PROPERTIES SWIG_DEFINITIONS "-shadow")

INCLUDE_DIRECTORIES(
  ${PYTHON_INCLUDE_DIRS}
  ${PTHREAD_INCLUDE_DIR} # pthread dependancy due to python2.7 library
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../FrontTrack
  )

SWIG_ADD_MODULE(FrontTrack python FrontTrack.i)
SWIG_LINK_LIBRARIES(FrontTrack ${PYTHON_LIBRARIES} ${PLATFORM_LIBS} FrontTrack)

IF(WIN32)
  SET_TARGET_PROPERTIES(_FrontTrack PROPERTIES DEBUG_OUTPUT_NAME _FrontTrack_d)
ENDIF(WIN32)
INSTALL(TARGETS ${SWIG_MODULE_FrontTrack_REAL_NAME} DESTINATION ${SALOME_INSTALL_PYTHON})

SALOME_INSTALL_SCRIPTS(${CMAKE_CURRENT_BINARY_DIR}/FrontTrack.py ${SALOME_INSTALL_PYTHON})