# Find python directories
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# boost
find_package(Boost COMPONENTS python REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# Include the header file directories
include_directories(${CMAKE_SOURCE_DIR}/include ${XCSIT_INCLUDE})

# Compiler flags
if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -std=c++11")
endif()

# =============================================================================
# 	   Compile the different c++ classes to shared objects
# =============================================================================

# PhotonEntry

add_library(PhotonEntry_ext SHARED PhotonEntry.cc PhotonEntry_ext.cc ${XCSIT_INCLUDE}/XPhotonEntry.hh ${CMAKE_SOURCE_DIR}/include/PhotonEntry.hh)
target_link_libraries(PhotonEntry_ext ${Boost_LIBRARIES})
set_target_properties(PhotonEntry_ext PROPERTIES PREFIX "")

# InteractionEntry

add_library(InteractionEntry_ext SHARED InteractionEntry.cc InteractionEntry_ext.cc ${XCSIT_INCLUDE}/XInteractionEntry.hh ${CMAKE_SOURCE_DIR}/include/InteractionEntry.hh)
target_link_libraries(InteractionEntry_ext ${Boost_LIBRARIES})
set_target_properties(InteractionEntry_ext PROPERTIES PREFIX "")

# PhotonData

add_library(PhotonData_ext SHARED ${CMAKE_SOURCE_DIR}/include/PhotonData.hh PhotonData.cc ${XCSIT_INCLUDE}/XPhotonData.hh ${XCSIT_INCLUDE}/XPhotonEntry.hh ${CMAKE_SOURCE_DIR}/include/PhotonEntry.hh PhotonEntry.cc PhotonData_ext.cc )
target_link_libraries(PhotonData_ext ${Boost_LIBRARIES})
set_target_properties(PhotonData_ext PROPERTIES PREFIX "")

# InteractionData

add_library(InteractionData_ext SHARED
${CMAKE_SOURCE_DIR}/include/InteractionData.hh InteractionData.cc
${XCSIT_INCLUDE}/XInteractionData.hh ${XCSIT_INCLUDE}/XInteractionEntry.hh
${CMAKE_SOURCE_DIR}/include/InteractionEntry.hh InteractionEntry.cc
InteractionData_ext.cc)
target_link_libraries(InteractionData_ext ${Boost_LIBRARIES})
set_target_properties(InteractionData_ext PROPERTIES PREFIX "")



