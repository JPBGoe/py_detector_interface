# Find python directories
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# boost
find_package(Boost COMPONENTS python REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# Include the header file directories
include_directories(
	${CMAKE_SOURCE_DIR}/include 
	${XCSIT_INCLUDE} ${XCSIT_SRC}
)

# Compiler flags
if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

# =============================================================================
# 	   Compile the different c++ classes to shared objects
# =============================================================================

# PhotonEntry

add_library(PhotonEntry_ext SHARED 
	PhotonEntry.cc PhotonEntry_ext.cc 
	${XCSIT_INCLUDE}/XPhotonEntry.hh 
	${CMAKE_SOURCE_DIR}/include/PhotonEntry.hh
)
target_link_libraries(PhotonEntry_ext ${Boost_LIBRARIES})
set_target_properties(PhotonEntry_ext PROPERTIES PREFIX "")

# InteractionEntry

add_library(InteractionEntry_ext SHARED 
	InteractionEntry.cc InteractionEntry_ext.cc 
	${XCSIT_INCLUDE}/XInteractionEntry.hh 
	${CMAKE_SOURCE_DIR}/include/InteractionEntry.hh
)
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
	InteractionData_ext.cc
)
target_link_libraries(InteractionData_ext ${Boost_LIBRARIES})
set_target_properties(InteractionData_ext PROPERTIES PREFIX "")

# ParticleSim

add_library(ParticleSim_ext SHARED 
	${CMAKE_SOURCE_DIR}/include/ParticleSim.hh ParticleSim.cc ParticleSim_ext.cc
	${XCSIT_INCLUDE}/XGeant4ParticleSim.hh
	${XCSIT_SRC}/XGeant4ParticleSim.cc
	${XCSIT_INCLUDE}/XPerfectSingleCharge.hh
)
target_include_directories(ParticleSim_ext PUBLIC 
	${GEANT4_FOLDER}/source/run/include
	${GEANT4_FOLDER}/source/global/management/include
	${GEANT4_FOLDER}/source/global/HEPRandom/include
	${GEANT4_FOLDER}/source/global/HEPGeometry/include
	${GEANT4_FOLDER}/source/global/HEPNumerics/include
	${GEANT4_FOLDER}/source/track/include
	${GEANT4_FOLDER}/source/event/include
	${GEANT4_FOLDER}/source/externals/clhep/include
	${GEANT4_FOLDER}/source/geometry/management/include
	${GEANT4_FOLDER}/source/geometry/solids/CSG/include
	${GEANT4_FOLDER}/source/geometry/solids/specific/include
	${GEANT4_FOLDER}/source/geometry/solids/Boolean/include
	${GEANT4_FOLDER}/source/geometry/division/include
	${GEANT4_FOLDER}/source/geometry/biasing/include
	${GEANT4_FOLDER}/source/geometry/navigation/include
	${GEANT4_FOLDER}/source/geometry/volumes/include
	${GEANT4_FOLDER}/source/particles/magneticfield/include
	${GEANT4_FOLDER}/source/particles/management/include
	${GEANT4_FOLDER}/source/materials/include
	${GEANT4_FOLDER}/source/tracking/include
	${GEANT4_FOLDER}/source/processes/biasing/include
	${GEANT4_FOLDER}/source/processes/cuts/include
	${GEANT4_FOLDER}/source/processes/electromagnetic/include
	${GEANT4_FOLDER}/source/processes/hardronic/include
	${GEANT4_FOLDER}/source/processes/management/include
	${GEANT4_FOLDER}/source/processes/parameterisation/include
	${GEANT4_FOLDER}/source/processes/scoring/include
	${GEANT4_FOLDER}/source/processes/decay/include
	${GEANT4_FOLDER}/source/processes/optical/include
	${GEANT4_FOLDER}/source/processes/phonon/include
	${GEANT4_FOLDER}/source/processes/transportation/include
	${GEANT4_FOLDER}/source/intercoms/include					#
	${GEANT4_FOLDER}/source/digits_hits/detector/include					
	${GEANT4_FOLDER}/source/digits_hits/digits/include					
	${GEANT4_FOLDER}/source/digits_hits/hits/include					
	${GEANT4_FOLDER}/source/digits_hits/scorer/include					
	${GEANT4_FOLDER}/source/digits_hits/utils/include					
	${GEANT4_FOLDER}/source/graphics_reps/include					
	${GEANT4_FOLDER}/source/persistency/gdml/include
	${XERCES}					
)
target_link_libraries(ParticleSim_ext ${Boost_LIBRARIES})
set_target_properties(ParticleSim_ext PROPERTIES PREFIX "")

# ChargeMatrix

add_library(ChargeMatrix_ext SHARED
	${XCSIT_INCLUDE}/XChargeMatrix.hh
	${XCSIT_SRC}/XChargeMatrix.cc
	ChargeMatrix_ext.cc
)
target_include_directories(ChargeMatrix_ext PUBLIC 
	${CIMG}/include
)
target_link_libraries(ChargeMatrix_ext ${Boost_LIBRARIES})
set_target_properties(ChargeMatrix_ext PROPERTIES PREFIX "")

# ChargeSimulation

add_library(ChargeSim_ext SHARED
	${CMAKE_SOURCE_DIR}/include/ChargeSim.hh ChargeSim.cc ChargeSim_ext.cc
	${XCSIT_INCLUDE}/XPlasmaPointChargeSim.hh
	${XCSIT_SRC}/XPlasmaPointChargeSim.cc
)
target_include_directories(ChargeSim_ext PUBLIC
	${GEANT4_FOLDER}/source/run/include
	${GEANT4_FOLDER}/source/global/management/include
	${GEANT4_FOLDER}/source/global/HEPRandom/include
	${GEANT4_FOLDER}/source/global/HEPGeometry/include
	${GEANT4_FOLDER}/source/global/HEPNumerics/include
	${GEANT4_FOLDER}/source/track/include
	${GEANT4_FOLDER}/source/event/include
	${GEANT4_FOLDER}/source/externals/clhep/include
	${GEANT4_FOLDER}/source/geometry/management/include
	${GEANT4_FOLDER}/source/geometry/solids/CSG/include
	${GEANT4_FOLDER}/source/geometry/solids/specific/include
	${GEANT4_FOLDER}/source/geometry/solids/Boolean/include
	${GEANT4_FOLDER}/source/geometry/division/include
	${GEANT4_FOLDER}/source/geometry/biasing/include
	${GEANT4_FOLDER}/source/geometry/navigation/include
	${GEANT4_FOLDER}/source/geometry/volumes/include
	${GEANT4_FOLDER}/source/particles/magneticfield/include
	${GEANT4_FOLDER}/source/particles/management/include
	${GEANT4_FOLDER}/source/materials/include
	${GEANT4_FOLDER}/source/tracking/include
	${GEANT4_FOLDER}/source/processes/biasing/include
	${GEANT4_FOLDER}/source/processes/cuts/include
	${GEANT4_FOLDER}/source/processes/electromagnetic/include
	${GEANT4_FOLDER}/source/processes/hardronic/include
	${GEANT4_FOLDER}/source/processes/management/include
	${GEANT4_FOLDER}/source/processes/parameterisation/include
	${GEANT4_FOLDER}/source/processes/scoring/include
	${GEANT4_FOLDER}/source/processes/decay/include
	${GEANT4_FOLDER}/source/processes/optical/include
	${GEANT4_FOLDER}/source/processes/phonon/include
	${GEANT4_FOLDER}/source/processes/transportation/include
	${GEANT4_FOLDER}/source/intercoms/include					#
	${GEANT4_FOLDER}/source/digits_hits/detector/include					
	${GEANT4_FOLDER}/source/digits_hits/digits/include					
	${GEANT4_FOLDER}/source/digits_hits/hits/include					
	${GEANT4_FOLDER}/source/digits_hits/scorer/include					
	${GEANT4_FOLDER}/source/digits_hits/utils/include					
	${GEANT4_FOLDER}/source/graphics_reps/include					
	${GEANT4_FOLDER}/source/persistency/gdml/include
	${XERCES}
	${CIMG}/include					
)
target_link_libraries(ChargeSim_ext ${Boost_LIBRARIES})
set_target_properties(ChargeSim_ext PROPERTIES PREFIX "")

