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
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

add_library(PhotonEntry_ext SHARED PhotonEntry.cc PhotonEntry_ext.cc ${XCSIT_INCLUDE}/XPhotonEntry.hh ${CMAKE_SOURCE_DIR}/include/PhotonEntry.hh)
target_link_libraries(PhotonEntry_ext ${Boost_LIBRARIES})

set_target_properties(PhotonEntry_ext PROPERTIES PREFIX "")
