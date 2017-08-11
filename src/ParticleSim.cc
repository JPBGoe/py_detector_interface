/*
 * Instances of this class provide an easy access to the
 * XCSIT::XGeant4ParticleSim class since it uses defaults to setup the
 * dettector.
 *
 * File: 	ParticleSim.hh
 * Author:	jburchert
 * Date:	10 August 2017
 */

#include "ParticleSim.hh"
#include <stdexcept>

namespace DSIM{

	ParticleSim::ParticleSim(){
	}

	ParticleSim::~ParticleSim(){
	} // delete a lot of pointers

	// Already implemented in XGeant4ParticleSim.cc
		// void InitializeSimulation();
		// void runSimulation();
		// void runSimulation(boost::shared_ptr<XCSIT::XPhotonData> input, boost::shared_ptr<XCSIT::XInteractionData> output);
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
    
	void ParticleSim::initialization(string detectorname){
    
    	// 1st: Set the Geometry
    	setDetector(detectorname);
    
    	// 2nd: Set the physics list
    	SetPhysicsList(new XCSIT::XPhysicsList);

    	// 3rd: PrimaryGenerator, idx.e. fill the initial input container
    	SetPrimaryGeneratorAction(new XCSIT::XPrimaryGeneratorAction);

    	// 4th: Event Action allows the user to modify G4 behavior before and after and event
    	// In case of X-CSIT, the interaction data is stored.
    	SetEventAction(new XCSIT::XEventAction);
	}

	void ParticleSim::setDetector(string detectorname){
    	if(construction == "pnCCD"){
	        SetDetectorConstruction(new XCSIT::PNCCDDetectorConstruction);
   		}else if(construction == "LPD"){
        	SetDetectorConstruction(new XCSIT::LPDDetectorConstruction);
    	}else if(construction == "AGIPD"){
        	SetDetectorConstruction(new XCSIT::AGIPDDetectorConstruction);
    	}else if(construction == "AGIPDSPB"){
        	SetDetectorConstruction(new XCSIT::AGIPDSPBDetectorConstruction);
    	}else if(construction == "CAD"){
			XCSIT::CadDetectorConstruction* detector = new XCSIT::CadDetectorConstruction();
        	detector->ConstructFromGdml("cadFile");
        	SetDetectorConstruction(detector);
			delete detector;
    	}else{
			throw std::invalid_argument("The specified detector is of unknown type. Please check again");
    	}
	}
 
}
