/*
 * Instances of this class provide an easy access to the
 * XCSIT::XGeant4ParticleSim class since it uses defaults to setup the
 * dettector.
 *
 * File: 	ParticleSim.hh
 * Author:	jburchert
 * Date:	11 August 2017
 */

#include "ParticleSim.hh"
#include "XGeant4ParticleSim.hh"
#include <stdexcept>

namespace DSIM{

	ParticleSim::ParticleSim(){
	}

	ParticleSim::~ParticleSim(){
	} // delete a lot of pointers

	// Already implemented in XGeant4ParticleSim.cc
		// void InitializeSimulation();
		// void runSimulation();
		// void runSimulationv(boost::shared_ptr<XCSIT::XPhotonData> input, boost::shared_ptr<XCSIT::XInteractionData> output);
		// virtual void ResetRunManager();
		// void SetDetectorConstruction(XCSIT::G4VUserDetectorConstruction* inputDetectorConstruction);
		// void SetPhysicsList(XCSIT::G4VUserPhysicsList* inputPhysicsList);
		// void SetPrimaryGeneratorAction(XCSIT::XPrimaryGeneratorAction* inputPrimaryGeneratorAction);
		// void SetEventAction(XCSIT::XEventAction* inputEventAction);
		// void SetInput(boost::shared_ptr<XCSIT::XPhotonData> input);
		// void SetOutput(boost::shared_ptr<XCSIT::XInteractionData> output);
		// XCSIT::G4RunManager* ParticleSim::GetRunManager(){return runManager;}
		// XCSIT::G4VUserDetectorConstruction* ParticleSim::GetSimDetectorConstruction(){return simDetectorConstruction;}
		// XCSIT::G4VUserPhysicsList* ParticleSim::GetSimPhysicsList(){return simPhysicsList;}
		// XCSIT::XPrimaryGeneratorAction* ParticleSim::GetSimPrimaryGeneratorAction(){return simPrimaryGeneratorAction;}
		// XCSIT::XEventAction* ParticleSim::GetEventAction(){return simEventAction;}
    
	void ParticleSim::initialization(std::string detectorname){
        std::cout << "ParticleSim::initialization << " << detectorname << std::endl;
    	// 1st: Set the Geometry
    	setDetector(detectorname);
    
    	// 2nd: Set the physics list
    	XCSIT::XGeant4ParticleSim::SetPhysicsList(new XCSIT::XPhysicsList);

    	// 3rd: PrimaryGenerator, idx.e. fill the initial input container
    	XCSIT::XGeant4ParticleSim::SetPrimaryGeneratorAction(new XCSIT::XPrimaryGeneratorAction);

    	// 4th: Event Action allows the user to modify G4 behavior before and after and event
    	// In case of X-CSIT, the interaction data is stored.
    	XCSIT::XGeant4ParticleSim::SetEventAction(new XCSIT::XEventAction);
	}

	void ParticleSim::setDetector(std::string detectorname){
        std::cout << "ParticleSim::setDetector << " << detectorname << std::endl;
    	
        if(detectorname == DetectorType[0]){
	        XCSIT::XGeant4ParticleSim::SetDetectorConstruction(new XCSIT::PNCCDDetectorConstruction);
   		}else if(detectorname == DetectorType[1]){
        	XCSIT::XGeant4ParticleSim::SetDetectorConstruction(new XCSIT::LPDDetectorConstruction);
    	}else if(detectorname == DetectorType[2]){
        	XCSIT::XGeant4ParticleSim::SetDetectorConstruction(new XCSIT::AGIPDDetectorConstruction);
    	}else if(detectorname == DetectorType[3]){
        	XCSIT::XGeant4ParticleSim::SetDetectorConstruction(new XCSIT::AGIPDSPBDetectorConstruction);
    	}else if(detectorname == DetectorType[4]){
			XCSIT::CadDetectorConstruction* detector = new XCSIT::CadDetectorConstruction();
        	detector->ConstructFromGdml("cadFile");
        	XCSIT::XGeant4ParticleSim::SetDetectorConstruction(detector);
			delete detector;
    	}else{
			throw std::invalid_argument("The specified detector is of unknown type. Please check again");
    	}
        
	}


	void ParticleSim::runSimulation(boost::shared_ptr<XCSIT::XPhotonData> input, boost::shared_ptr<XCSIT::XInteractionData> output){
        std::cout<< "ParticleSim::runSimulation start" << (input.get())->size() << "," << (output.get())->size() << std::endl;
		XCSIT::XGeant4ParticleSim::runSimulation(input,output);
        std::cout<< "ParticleSim::runSimulation finished" << (input.get())->size() << "," << (output.get())->size() << std::endl;
	}
}
