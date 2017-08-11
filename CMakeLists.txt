project(py_detector_interface)

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

# Determine the folder where the source code of xcsit is located
option(XCSIT_FOLDER "Path xcsit parent folder: -DXCSIT_FOLDER=<path> if <path>/xcsit
     <path> is either absolut or relative from your build folder")
#if(NOT XCSIT_FOLDER)
#   find_path(XCSIT_FOLDER xcsit/include)
#endif()
if(NOT XCSIT_FOLDER)
   message(FATAL_ERROR "Path to xcsit source folders could not be found. "
      "Please use -DXCSIT_FOLDER=<path> if <path>/xcsit"
    " <path> is either absolut or relative from your build folder")
endif()

# Determine the folder where the source code of geant4 is located
option(GEANT4_FOLDER "Path geant4 source parent folder: -DGEANT4_FOLDER=<path> if
 <path>/source <path> is either absolut or relative from your build folder to 
 the parentfolder of source. In source there should be subfolders such as 
 run/src and include/src containing the source code of geant4")
#if(NOT GEANT4_FOLDER)
#   find_path(GEANT4_FOLDER geant4/include)
#endif()
if(NOT GEANT4_FOLDER)
   message(FATAL_ERROR "Path to geant4 source folders could not be found. "
      "Please use -DGEANT_FOLDER=<path> if <path>/geant4"
    " <path> is either absolut or relative from your build folder")
endif()

option(XERCES "XERCES path")

# Define path to include files and source files
set(XCSIT_INCLUDE ${XCSIT_FOLDER}/include)
set(XCSIT_SRC ${XCSIT_FOLDER}/src)

# Specify the source elements needed from xcsit
list(APPEND IN_LIST "XPhotonEntry.hh" "XPhotonData.hh" "XInteractionEntry.hh" 
    "XInteractionData.hh" "XGeant4ParticleSim.hh" "XChargeMatrix.hh" "XChargeSim.hh")
list(APPEND SRC_LIST "XGeant4ParticleSim.cc" "XChargeMatrix.cc")

# Check if the required source files are present
foreach(i IN LISTS IN_LIST)
   if(NOT EXISTS ${XCSIT_INCLUDE}/${i}) 
      message(FATAL_ERROR "Could not file ${i} at ${XCSIT_INCLUDE}")
   endif()
endforeach()
foreach(i IN LISTS SRC_LIST)
   if(NOT EXISTS ${XCSIT_SRC}/${i}) 
      message(FATAL_ERROR "Could not file ${i} at ${XCSIT_SRC}")
   endif()
endforeach()

# Include SimEx path files


# Find status return
message(STATUS "All required files and libraries found")

# Set entvironmental variables
configure_file(env.sh.in env.sh)

# Branch
add_subdirectory(src)





