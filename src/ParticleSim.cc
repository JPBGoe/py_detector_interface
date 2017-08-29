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
		simulate = new XCSIT::XGeant4ParticleSim();
	}

	ParticleSim::~ParticleSim(){
		delete simulate;
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
    
    	// 1st: Set the Geometry
    	setDetector(detectorname);
    
    	// 2nd: Set the physics list
    	simulate->SetPhysicsList(new XCSIT::XPhysicsList);

    	// 3rd: PrimaryGenerator, idx.e. fill the initial input container
    	simulate->SetPrimaryGeneratorAction(new XCSIT::XPrimaryGeneratorAction);

    	// 4th: Event Action allows the user to modify G4 behavior before and after and event
    	// In case of X-CSIT, the interaction data is stored.
    	simulate->SetEventAction(new XCSIT::XEventAction);
	}

	void ParticleSim::setDetector(std::string detectorname){
    	if(detectorname == DetectorType[0]){
	        simulate->SetDetectorConstruction(new XCSIT::PNCCDDetectorConstruction);
   		}else if(detectorname == DetectorType[1]){
        	simulate->SetDetectorConstruction(new XCSIT::LPDDetectorConstruction);
    	}else if(detectorname == DetectorType[2]){
        	simulate->SetDetectorConstruction(new XCSIT::AGIPDDetectorConstruction);
    	}else if(detectorname == DetectorType[3]){
        	simulate->SetDetectorConstruction(new XCSIT::AGIPDSPBDetectorConstruction);
    	}else if(detectorname == DetectorType[4]){
			XCSIT::CadDetectorConstruction* detector = new XCSIT::CadDetectorConstruction();
        	detector->ConstructFromGdml("cadFile");
        	simulate->SetDetectorConstruction(detector);
			delete detector;
    	}else{
			throw std::invalid_argument("The specified detector is of unknown type. Please check again");
    	}
	}


	void ParticleSim::runSimulation(boost::shared_ptr<XCSIT::XPhotonData> input, boost::shared_ptr<XCSIT::XInteractionData> output){
		simulate->SetInput(input);
		simulate->SetOutput(output);
		simulate->runSimulation();
	}
}
