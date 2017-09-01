#
#   cmake file to compile the interface between the CERN simulation framework
#   geant4, its wrapper class xcsit and the XCSITDetectorSimulation class of the
#   SimEx framework.
#
#	File:	./CMakeLists.txt
#	Author:	jburchert
#	Date:	18 August 2017
#

# =============================================================================
#                       Options, Version, Variables
# =============================================================================

# project name
project(py_detector_interface)

# required version
cmake_minimum_required(VERSION 2.4)

# Policy
if(POLICY CMP0012)
  cmake_policy(SET CMP0012 NEW)
endif()


# Disallow in-source build
if ("${CMAKE_SOURCE_DIR}"  STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "SIMEX requires an out of source Build. "
    "Please create a separate binary directory and run CMake there using 'cmake ..'")
endif()

# check if this OS is a linux system
if(NOT UNIX)
    message(FATAL_ERROR "This cmake file supports only Unix operation systems")
endif()

# Check the compiler version if gnu
# Check the compiler version if gnu
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") 
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
        message(WARINING "During development GCC GNU comiler 4.8.5 used.
            Your version might not work")
    endif()
endif()

# Specify options
option(GEANT4_ROOT "-DGEANT4_ROOT=<abs path> absolute path to the geant4
    installation directory that includes \n
    ./bin/\n
    ./include/Geant4/\n
    ./lib64/Geant4-<ver>/\n
    ./share/Geant4-<ver>/data/"
)
option(XERCESC_ROOT "-DXERCESC_ROOT=<abs path> absolute path to the xercesc
    installation directory that includes\n
    ./include/xercesc/\n
    ./lib/"
)
option(XCSIT_ROOT "-DXCSIT_ROOT=<abs path> absolute path to the xcist 
    installation directory that includes\n
    ./include/xcsit/
    ./lib/
    ./lib/xcsit/
    ./bin/"
)
option(BOOST_ROOT "-DBOOST_ROOT=<abs path> absolute path to the boost
    installation directory that includes\n
    ./include/boost/
    ./lib/"
)
option(DEBUG "-DDEBUG sets all the necessary flages to compile with 
    additional output"
)


# Check if there is user input
if(NOT GEANT4_ROOT)
    message(FATAL_ERROR "Path to geant4 install root has to be specified")
endif()
if(NOT XERCESC_ROOT)
    message(FATAL_ERROR "Path to xercesc install root has to be specified")
endif()
if(NOT XCSIT_ROOT)
    message(FATAL_ERROR "Path to xcsit install root has to be specified")
endif()
if(NOT BOOST_ROOT)
    message(FATAL_ERROR "Path to boost install root has to be specified")
endif()
if(NOT DEBUG)
    set(DEBUG OFF)
    message(STATUS "Compilation type: release mode")
else()
    message(STATUS "Compilation type: debug mode")
endif()


# Branch
add_subdirectory(src)

# Create a file to set environmental variables for the geant4 installation
configure_file(py_detector_interface_env.sh.in py_detector_interface_env.sh)

# =============================================================================
#                           Create a package
# =============================================================================
export(TARGETS py_detector_interface FILE
    "${CMAKE_BINARY_DIR}/cmake/py_detector_interfaceTargets.cmake")
export(PACKAGE py_detector_interface)

configure_file(${CMAKE_SOURCE_DIR}/cmake/py_detector_interfaceConfig.cmake.in 
    ${CMAKE_BINARY_DIR}/cmake/py_detector_interfaceConfig.cmake)
configure_file(${CMAKE_SOURCE_DIR}/cmake/py_detector_interfaceConfigVersion.cmake.in 
    ${CMAKE_BINARY_DIR}/cmake/py_detector_interfaceConfigVersion.cmake)

# ============================================================================-
#                               Install
# ============================================================================-

# Variables
set(pdi_BINARY_DIR ${CMAKE_INSTALL_PREFIX}/bin)
set(pdi_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/py_detector_interface)
set(pdi_LIBRARIES ${CMAKE_INSTALL_PREFIX}/lib/)
set(pdi_CMAKE ${CMAKE_INSTALL_PREFIX}/lib/py_detector_interface)

# install/ copy the files
install(FILES ${CMAKE_BINARY_DIR}/py_detector_interface_env.sh DESTINATION ${pdi_BINARY_DIR} 
    PERMISSIONS 
    OWNER_READ
    OWNER_WRITE
    GROUP_READ
    WORLD_READ
)
install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/" DESTINATION ${pdi_INCLUDE_DIR}
    FILES_MATCHING 
    PATTERN "*.hh"
    PATTERN "*.h"
)
install(FILES ${CMAKE_BINARY_DIR}/src/libpy_detector_interface.so DESTINATION ${pdi_LIBRARIES}
    PERMISSIONS 
    OWNER_READ
    OWNER_EXECUTE
    OWNER_WRITE
    GROUP_READ
    GROUP_EXECUTE
    WORLD_READ
    WORLD_EXECUTE
)
install(DIRECTORY ${CMAKE_BINARY_DIR}/cmake/ DESTINATION ${pdi_CMAKE}
    FILES_MATCHING
    PATTERN "*.cmake"
)


install(CODE "MESSAGE(\"The installation of py_detector_interface is finished. \n\n
The folder structure is as follows:\n
+CMAKE_INSTALL_PREFIX
+-bin
+--py_detector_interface_env.sh
+-include
+--py_detector_interface
+---ChargeEntry.hh
+---...
+---PhotonEntry.hh
+-lib
+--py_detector_interface
+---py_detector_interfaceConfig.cmake
+---py_detector_interfaceTargets.cmake
+---py_detector_interfaceConfigVersion.cmake
+--libpy_detector_interface.so\n\n
\")")

