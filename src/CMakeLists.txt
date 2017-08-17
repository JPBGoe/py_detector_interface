# Find python directories
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# boost
find_package(Boost COMPONENTS python REQUIRED)
include_directories(${Boost_INCLUDE_DIR})


# Compiler flags
if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wl,--unresolved-symbols=report-all -Wl,--warn-unresolved-symbols")
endif()

# =============================================================================
# 	   Compile the different c++ classes to shared objects
# =============================================================================
# PhotonEntry

add_library(PhotonEntry_ext SHARED
	PhotonEntry.cc 
	PhotonEntry_ext.cc 
)
target_include_directories(PhotonEntry_ext PUBLIC
	${XCSIT_INCLUDE} 
	${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(PhotonEntry_ext ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
set_target_properties(PhotonEntry_ext PROPERTIES PREFIX "")

# InteractionEntry

add_library(InteractionEntry_ext SHARED 
	InteractionEntry.cc 
	InteractionEntry_ext.cc 
)
target_include_directories(InteractionEntry_ext PUBLIC
	${XCSIT_INCLUDE} 
	${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(InteractionEntry_ext ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
set_target_properties(InteractionEntry_ext PROPERTIES PREFIX "")

# PhotonData

add_library(PhotonData_ext SHARED 
	PhotonData.cc 
	PhotonData_ext.cc
	PhotonEntry.cc 
	PhotonEntry_ext.cc
)
target_include_directories(PhotonData_ext PUBLIC
	${XCSIT_INCLUDE} 
	${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(PhotonData_ext ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
set_target_properties(PhotonData_ext PROPERTIES PREFIX "")
add_dependencies(PhotonData_ext PhotonEntry_ext)

# InteractionData

add_library(InteractionData_ext SHARED
	InteractionData.cc
	InteractionData_ext.cc
	InteractionEntry.cc
	InteractionEntry_ext.cc
)
target_include_directories(InteractionData_ext PUBLIC
	${XCSIT_INCLUDE} 
	${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(InteractionData_ext ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
set_target_properties(InteractionData_ext PROPERTIES PREFIX "")
add_dependencies(InteractionData_ext InteractionEntry_ext)

# ParticleSim
add_library(ParticleSim_ext SHARED 
	ParticleSim.cc 
	ParticleSim_ext.cc
	${XCSIT_SRC}/XGeant4ParticleSim.cc
	${XCSIT_SRC}/XPhysicsList.cc
	${XCSIT_SRC}/XPrimaryGeneratorAction.cc
	${XCSIT_SRC}/XEventAction.cc
	${XCSIT_SRC}/PNCCDDetectorConstruction.cc
	${XCSIT_SRC}/LPDDetectorConstruction.cc
	${XCSIT_SRC}/AGIPDDetectorConstruction.cc
	${XCSIT_SRC}/AGIPDSPBDetectorConstruction.cc
	${XCSIT_SRC}/CadDetectorConstruction.cc
	${XCSIT_SRC}/XDetectorConstruction.cc
	${XCSIT_SRC}/XSensitiveDetector.cc
	${XCSIT_SRC}/XDetectorHits.cc
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLParser.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLReadStructure.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLRead.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLEvaluator.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLWriteStructure.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLMessenger.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLWrite.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLReadDefine.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLReadSetup.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLReadParamvol.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLReadSolids.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLReadMaterials.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLWriteParamvol.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLWriteDefine.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLWriteMaterials.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLWriteSolids.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLParameterisation.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4STRead.cc	
/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source/persistency/gdml/src/G4GDMLWriteSetup.cc	
)
target_include_directories(ParticleSim_ext PUBLIC
	${CMAKE_SOURCE_DIR}/include 
	${XCSIT_INCLUDE}
	${XCSIT_SRC}
	${XERCES}
	${GEANT4_FOLDER}/source/event/include
	${GEANT4_FOLDER}/source/global/management/include
	${GEANT4_FOLDER}/source/global/HEPRandom/include
	${GEANT4_FOLDER}/source/global/HEPGeometry/include
	${GEANT4_FOLDER}/source/global/HEPNumerics/include
	${GEANT4_FOLDER}/source/persistency/gdml/include
	${GEANT4_FOLDER}/source/run/include
	${GEANT4_FOLDER}/source/externals/clhep/include
	${GEANT4_FOLDER}/source/externals/expat/include
	${GEANT4_FOLDER}/source/externals/zlib/include
	${GEANT4_FOLDER}/source/materials/include
	${GEANT4_FOLDER}/source/physics_lists/builders/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/electromagnetic/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/gamma_lepto_nuclear/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/hadron_elastic/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/limiters/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/decay/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/factory/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/hadron_inelastic/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/ions/include
	${GEANT4_FOLDER}/source/physics_lists/constructors/stopping/include
	${GEANT4_FOLDER}/source/physics_lists/lists/include
	${GEANT4_FOLDER}/source/physics_lists/util/include
	${GEANT4_FOLDER}/source/track/include
	${GEANT4_FOLDER}/source/digits_hits/detector/include					
	${GEANT4_FOLDER}/source/digits_hits/digits/include					
	${GEANT4_FOLDER}/source/digits_hits/hits/include					
	${GEANT4_FOLDER}/source/digits_hits/scorer/include					
	${GEANT4_FOLDER}/source/digits_hits/utils/include					
	${GEANT4_FOLDER}/source/graphics_reps/include					
	${GEANT4_FOLDER}/source/processes/biasing/include
	${GEANT4_FOLDER}/source/processes/cuts/include
	${GEANT4_FOLDER}/source/processes/electromagnetic/utils/include
	${GEANT4_FOLDER}/source/processes/hardronic/include
	${GEANT4_FOLDER}/source/processes/management/include
	${GEANT4_FOLDER}/source/processes/parameterisation/include
	${GEANT4_FOLDER}/source/processes/scoring/include
	${GEANT4_FOLDER}/source/processes/decay/include
	${GEANT4_FOLDER}/source/processes/optical/include
	${GEANT4_FOLDER}/source/processes/phonon/include
	${GEANT4_FOLDER}/source/processes/transportation/include
	${GEANT4_FOLDER}/source/tracking/include
	${GEANT4_FOLDER}/source/error_propagation/include
	${GEANT4_FOLDER}/source/geometry/biasing/include
	${GEANT4_FOLDER}/source/geometry/divisions/include
	${GEANT4_FOLDER}/source/geometry/magneticfield/include
	${GEANT4_FOLDER}/source/geometry/management/include
	${GEANT4_FOLDER}/source/geometry/navigation/include
	${GEANT4_FOLDER}/source/geometry/solids/CSG/include
	${GEANT4_FOLDER}/source/geometry/solids/specific/include
	${GEANT4_FOLDER}/source/geometry/solids/Boolean/include
	${GEANT4_FOLDER}/source/geometry/volumes/include
	${GEANT4_FOLDER}/source/intercoms/include					#
	${GEANT4_FOLDER}/source/particles/adjoint/include
	${GEANT4_FOLDER}/source/particles/bosons/include
	${GEANT4_FOLDER}/source/particles/hadrons/mesons/include
	${GEANT4_FOLDER}/source/particles/hadrons/ions/include
	${GEANT4_FOLDER}/source/particles/hadrons/barions/include
	${GEANT4_FOLDER}/source/particles/leptons/include
	${GEANT4_FOLDER}/source/particles/management/include
	${GEANT4_FOLDER}/source/particles/shortlived/include
	${GEANT4_FOLDER}/source/particles/utils/include
)
add_library(xer SHARED IMPORTED)
set_target_properties(xer PROPERTIES
	IMPORTED_LOCATION "${XERCES}/.libs/libxerces-c-3.1.so"
)

set(GEANT_SO "/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-install/lib64/")
add_library(clhep SHARED IMPORTED)
set_target_properties(clhep PROPERTIES IMPORTED_LOCATION
#	"${GEANT_SO}/libG4analysis.so"	
	"${GEANT_SO}/libG4clhep.so"	
#	"${GEANT_SO}/libG4geometry.so"	
#	"${GEANT_SO}/libG4modeling.so"	
#	"${GEANT_SO}/libG4readout.so"	
#	"${GEANT_SO}/libG4visXXX.so"	
#	"${GEANT_SO}/libG4global.so"	
#	"${GEANT_SO}/libG4parmodels.so"	
#	"${GEANT_SO}/libG4run.so"	
#	"${GEANT_SO}/libG4VRML.so"	
#	"${GEANT_SO}/libG4GMocren.so"	
#	"${GEANT_SO}/libG4particles.so"	
#	"${GEANT_SO}/libG4tracking.so"	
#	"${GEANT_SO}/libG4zlib.so"	
#	"${GEANT_SO}/libG4digits_hits.so"	
#	"${GEANT_SO}/libG4graphics_reps.so"	
#	"${GEANT_SO}/libG4persistency.so"	
#	"${GEANT_SO}/libG4track.so"	
#	"${GEANT_SO}/libG4error_propagation.so"	
#	"${GEANT_SO}/libG4intercoms.so"	
#	"${GEANT_SO}/libG4physicslists.so"	
#	"${GEANT_SO}/libG4Tree.so"	
#	"${GEANT_SO}/libG4event.so"	
#	"${GEANT_SO}/libG4interfaces.so"	
#	"${GEANT_SO}/libG4processes.so"	
#	"${GEANT_SO}/libG4visHepRep.so"	
#	"${GEANT_SO}/libG4FR.so"	
#	"${GEANT_SO}/libG4materials.so"	
#	"${GEANT_SO}/libG4RayTracer.so"	
#	"${GEANT_SO}/libG4vis_management.so"	
)
add_library(analysis SHARED IMPORTED)
set_target_properties(analysis PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4analysis.so"	
)
add_library(geometry SHARED IMPORTED)
set_target_properties(geometry PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4geometry.so"	
)
add_library(modeling SHARED IMPORTED)
set_target_properties(modeling PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4modeling.so"	
)
add_library(readout SHARED IMPORTED)
set_target_properties(readout PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4readout.so"	
)
add_library(visXXX SHARED IMPORTED)
set_target_properties(visXXX PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4visXXX.so"	
)
add_library(global SHARED IMPORTED)
set_target_properties(global PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4global.so"	
)
add_library(parmodels SHARED IMPORTED)
set_target_properties(parmodels PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4parmodels.so"	
)
add_library(run SHARED IMPORTED)
set_target_properties(run PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4run.so"	
)
add_library(VRML SHARED IMPORTED)
set_target_properties(VRML PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4VRML.so"	
)
add_library(Mocren SHARED IMPORTED)
set_target_properties(Mocren PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4GMocren.so"	
)
add_library(particles SHARED IMPORTED)
set_target_properties(particles PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4particles.so"	
)
add_library(tracking SHARED IMPORTED)
set_target_properties(tracking PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4tracking.so"	
)
add_library(zlib SHARED IMPORTED)
set_target_properties(zlib PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4zlib.so"	
)
add_library(digits_hits SHARED IMPORTED)
set_target_properties(digits_hits PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4digits_hits.so"	
)
add_library(graphics_reps SHARED IMPORTED)
set_target_properties(graphics_reps PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4graphics_reps.so"	
)
add_library(persistency SHARED IMPORTED)
set_target_properties(persistency PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4persistency.so"	
)
add_library(track SHARED IMPORTED)
set_target_properties(track PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4track.so"	
)
add_library(error_propagation SHARED IMPORTED)
set_target_properties(error_propagation PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4error_propagation.so"	
)
add_library(intercoms SHARED IMPORTED)
set_target_properties(intercoms PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4intercoms.so"	
)
add_library(physicslists SHARED IMPORTED)
set_target_properties(physicslists PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4physicslists.so"	
)
add_library(Tree SHARED IMPORTED)
set_target_properties(Tree PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4Tree.so"	
)
add_library(event SHARED IMPORTED)
set_target_properties(event PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4event.so"	
)
add_library(interfaces SHARED IMPORTED)
set_target_properties(interfaces PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4interfaces.so"	
)
add_library(processes SHARED IMPORTED)
set_target_properties(processes PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4processes.so"	
)
add_library(visHepRep SHARED IMPORTED)
set_target_properties(visHepRep PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4visHepRep.so"	
)
add_library(FR SHARED IMPORTED)
set_target_properties(FR PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4FR.so"	
)
add_library(materials SHARED IMPORTED)
set_target_properties(materials PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4materials.so"	
)
add_library(RayTracer SHARED IMPORTED)
set_target_properties(RayTracer PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4RayTracer.so"	
)
add_library(vis_management SHARED IMPORTED)
set_target_properties(vis_management PROPERTIES IMPORTED_LOCATION
	"${GEANT_SO}/libG4vis_management.so"	
)








target_link_libraries(ParticleSim_ext 
	xer
	geometry
	modeling
	readout
	visXXX
	analysis
	global
	parmodels
	run
	VRML
	clhep
	Mocren
	particles
	tracking
	zlib
	digits_hits
	graphics_reps
	persistency
	track
	error_propagation
	intercoms
	physicslists
	Tree
	event
	interfaces
	processes
	visHepRep
	FR
	materials
	RayTracer
	vis_management
	${PYTHON_LIBRARIES} ${Boost_LIBRARIES}
)
set_target_properties(ParticleSim_ext PROPERTIES PREFIX "")
add_dependencies(ParticleSim_ext PhotonData_ext InteractionData_ext)

# ChargeEntry

add_library(ChargeEntry_ext SHARED
	ChargeEntry.cc 
	ChargeEntry_ext.cc
)
target_include_directories(ChargeEntry_ext PUBLIC
	${CMAKE_SOURCE_DIR}/include
	${XCSIT_INCLUDE}
)
target_link_libraries(ChargeEntry_ext ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
set_target_properties(ChargeEntry_ext PROPERTIES PREFIX "")


# ChargeMatrix

add_library(ChargeMatrix_ext SHARED
	ChargeMatrix.cc
	ChargeMatrix_ext.cc
	ChargeEntry.cc 
	ChargeEntry_ext.cc
)
target_include_directories(ChargeMatrix_ext PUBLIC
	${CMAKE_SOURCE_DIR}/include
	${XCSIT_INCLUDE}
)
target_link_libraries(ChargeMatrix_ext ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
set_target_properties(ChargeMatrix_ext PROPERTIES PREFIX "")
add_dependencies(ChargeMatrix_ext ChargeEntry_ext)

# ChargeSimulation

# source files which need to be compiled and liked to each other
add_library(ChargeSim_ext SHARED
	ChargeSim.cc 
	ChargeSim_ext.cc
	ChargeMatrix.cc
	ChargeEntry.cc
	InteractionEntry.cc
	${XCSIT_SRC}/XPlasmaPointChargeSim.cc
	${XCSIT_SRC}/XPlasmaCellPointerVector.cc
	${XCSIT_SRC}/PNCCDModuleDefinition.cc
	${XCSIT_SRC}/LPDModuleDefinition.cc
	${XCSIT_SRC}/AGIPDModuleDefinition.cc
	${XCSIT_SRC}/AGIPDSPBModuleDefinition.cc
	${XCSIT_SRC}/CadDummyModuleDefinition.cc
	${XCSIT_SRC}/XBlankPlasmaSim.cc
	${XCSIT_SRC}/XPointSpreadSingleCharge.cc
	${XCSIT_SRC}/XPointFanoSingleCharge.cc
	${XCSIT_SRC}/XPerfectSingleCharge.cc
	${XCSIT_SRC}/XBlankPlasmaSim.cc
	${XCSIT_SRC}/XBlankPlasmaCellSearch.cc
	${XCSIT_SRC}/XPlasmaCellList.cc
	${XCSIT_SRC}/XSimpleModuleDefinition.cc
	${XCSIT_SRC}/XPlasmaCellHist.cc
)
# The pathes have to point to all the directories where the imported .hh or .h
# files are located
target_include_directories(ChargeSim_ext PUBLIC
	${CMAKE_SOURCE_DIR}/include/
	${XCSIT_INCLUDE}
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
	${GEANT4_FOLDER}/source/intercoms/include					
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
target_link_libraries(ChargeSim_ext
	${PYTHON_LIBRARIES} 
	${Boost_LIBRARIES}
)
set_target_properties(ChargeSim_ext PROPERTIES PREFIX "")
add_dependencies(ChargeSim_ext InteractionData_ext ChargeMatrix_ext)


