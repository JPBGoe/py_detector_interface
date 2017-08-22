#
#	File:	CMakeLists.txt
#	Author:	jburchert
#	Date:	18 August 2017
#

# project name
project(py_detector_interface)

# required version
cmake_minimum_required(VERSION 2.4)

# Disallow in-source build
if ("${CMAKE_SOURCE_DIR}"  STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "SIMEX requires an out of source Build. "
    "Please create a separate binary directory and run CMake there using 'cmake ..'")
endif()

# check if this OS is a linux system
if(NOT UNIX)
    message(FATAL_ERROR "This cmake file supports only Unix operation systems")
endif()

# Specify diverse option
option(XCSIT_FOLDER "-DXCSIT_FOLDER=<path>/xcsit  Path to xcsit installation")
option(GEANT4_SOURCE "-DXCSIT_SOURCE=<path>/geant4.10.03.p01/source   Path to
	geant4 source files")
option(GEANT4_BUILD "-DXCSIT_SOURCE=<path>/geant4.10.03.p01-build   Path to
	geant4 build directory")
option(GEANT4_SO "-DXCSIT_SOURCE=<path>/geant4.10.03.p01i-install/lib64
	Path to geant4 shared objects")
option(XERCES "-DXERCES=<path>/xerces-c-3.1.4/src    Path to xercesc source
	files")

# Check options to be set
if(NOT XCSIT_FOLDER)
   message(FATAL_ERROR "Please specify: -DXCSIT_FOLDER=<path>/xcsit  Path to xcsit installation")
endif()
if(NOT GEANT4_SOURCE)
   message(FATAL_ERROR "Please specify: -DXCSIT_SOURCE=<path>/geant4.10.03.p01/source   Path to
	geant4 source files")
endif()
if(NOT GEANT4_BUILD)
   message(FATAL_ERROR "Please specify: -DXCSIT_BUILD=<path>/geant4.10.03.p01-build  Path to
	geant4 build directory")
endif()
if(NOT GEANT4_SO)
   message(FATAL_ERROR "Please specify: -DXCSIT_SOURCE=<path>/geant4.10.03.p01i-install/lib64
	Path to geant4 shared objects")
endif()
if(NOT XERCES)
   message(FATAL_ERROR "Please specify: -DXERCES=<path>/xerces-c-3.1.4/src    Path to xercesc source
	files ")
endif()

# Define path to include files and source files
set(XCSIT_INCLUDE ${XCSIT_FOLDER}/include)
set(XCSIT_SRC ${XCSIT_FOLDER}/src)

# Branch
add_subdirectory(src)

# Set entvironmental variables
configure_file(env.sh.in env.sh)

# Copy created shared objects and test to the build folder
install(DIRECTORY DESTINATION "${CMAKE_BINARY_DIR}/lib/")
install(DIRECTORY DESTINATION "${CMAKE_BINARY_DIR}/test/")
install(DIRECTORY DESTINATION "${CMAKE_BINARY_DIR}/python/")
install(DIRECTORY "${CMAKE_BINARY_DIR}/src/" DESTINATION
"${CMAKE_BINARY_DIR}/lib" FILES_MATCHING PATTERN "*.so"
PATTERN "*.a" PATTERN "CMakeFiles*" EXCLUDE)
install(DIRECTORY "${CMAKE_SOURCE_DIR}/test/" DESTINATION
"${CMAKE_BINARY_DIR}/test" FILES_MATCHING PATTERN "*.py"
PATTERN "CMakeFiles*" EXCLUDE)
install(DIRECTORY "${CMAKE_SOURCE_DIR}/src/" DESTINATION
"${CMAKE_BINARY_DIR}/python" FILES_MATCHING PATTERN "*.py"
PATTERN "CMakeFiles*" EXCLUDE)


