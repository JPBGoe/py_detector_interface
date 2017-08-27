# =============================================================================
# 	  			Find external packages and libraries 
# =============================================================================

# Find python directories
find_package(PythonLibs 2.7 REQUIRED)
message(STATUS "Found PythonLibs includes at:    ${PYTHON_INCLUDE_DIRS}")
include_directories(${PYTHON_INCLUDE_DIRS})

# boost
find_package(Boost COMPONENTS python REQUIRED)
message(STATUS "Found boost includes at:    ${Boost_INCLUDE_DIRS}")
include_directories(${Boost_INCLUDE_DIRS})

# find the Geant4 package
find_package(Geant4 REQUIRED
    HINTS ${GEANT4_ROOT}/lib64/Geant4-10.3.1/Geant4Config.cmake
)
message(STATUS "Found Geant4 includes at:      ${Geant4_INCLUDE_DIR}")
include_directories(
    ${Geant4_INCLUDE_DIR} 
    ${Geant4_INCLUDE_DIR}/CLHEP/Evaluation
    ${Geant4_INCLUDE_DIR}/CLHEP/Geometry
    ${Geant4_INCLUDE_DIR}/CLHEP/Random
    ${Geant4_INCLUDE_DIR}/CLHEP/Units
    ${Geant4_INCLUDE_DIR}/CLHEP/Utility
    ${Geant4_INCLUDE_DIR}/CLHEP/Vector
)

# xcsit
find_package(xcsit REQUIRED
    HINTS ${XCSIT_ROOT}/lib/xcsit/
)
message(STATUS "Found xcsit includes at:    ${xcsit_INCLUDE_DIRS}")
include_directories(${xcsit_INCLUDE_DIRS})


# xercesc library
add_library(xercesc SHARED IMPORTED)
set_target_properties(xercesc PROPERTIES
    IMPORTED_LOCATION ${XERCESC_ROOT}/lib/libxerces-c.so
)
include_directories(
    ${XERCESC_ROOT}/include/xercesc/dom 
    ${XERCESC_ROOT}/include/xercesc/framework
    ${XERCESC_ROOT}/include/xercesc/internal
    ${XERCESC_ROOT}/include/xercesc/parsers
    ${XERCESC_ROOT}/include/xercesc/sax
    ${XERCESC_ROOT}/include/xercesc/sax2
    ${XERCESC_ROOT}/include/xercesc/util
    ${XERCESC_ROOT}/include/xercesc/validators
    ${XERCESC_ROOT}/include/xercesc/xinclude
)

# include of this project
include_directories(${CMAKE_SOURCE_DIR}/include/)


#link_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS}
#${Geant4_INCLUDE_DIRS} ${xcsit_INCLUDE_DIRS})


# =============================================================================
# 	  				Compiler and Linker Flags
# =============================================================================

# Compiler flags
if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wl,--unresolved-symbols=report-all -Wl,--warn-unresolved-symbols")
endif()

# =============================================================================
# 	   Compile the different c++ classes to shared objects
# =============================================================================

# Create the library with all the content of this project
add_library(py_detector_interface SHARED
# Photon Entry
    PhotonEntry.cc 
	PhotonEntry_ext.cc 
# InteractionEntry
	InteractionEntry.cc 
	InteractionEntry_ext.cc 
# ChargeEntry
	ChargeEntry.cc 
	ChargeEntry_ext.cc
# PhotonData
	PhotonData.cc 
	PhotonData_ext.cc
# Interaction Data
	InteractionData.cc
	InteractionData_ext.cc
# ChargeMatrix
	ChargeMatrix.cc
	ChargeMatrix_ext.cc
# ParticleSim
	ParticleSim.cc 
	ParticleSim_ext.cc
# ChargeSIm
	ChargeSim.cc 
	ChargeSim_ext.cc
)
target_link_libraries(py_detector_interface 
    ${PYTHON_LIBRARIES}
    ${Boost_LIBRARIES}
    xercesc
    ${xcsit_LIBRARIES}
    ${Geant4_LIBRARIES}
)
