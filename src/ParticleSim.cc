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
       if(DEBUG){
            std::cout << "ParticleSim::ParticleSim" << std::endl;
        } 
	}

	ParticleSim::~ParticleSim(){
       if(DEBUG){
            std::cout << "ParticleSim::ParticleSim" << std::endl;
        }
	} 

	void ParticleSim::initialization(std::string detectorname){
        if(DEBUG){
            std::cout << "ParticleSim::initialization << " << detectorname << std::endl;
        }
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
        if(DEBUG){
            std::cout << "ParticleSim::setDetector << " << detectorname << std::endl;
    	}

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
        if(DEBUG){
            std::cout<< "ParticleSim::runSimulation start" << std::endl;
        }
		XCSIT::XGeant4ParticleSim::runSimulation(input,output);
        if(DEBUG){
            std::cout<< "ParticleSim::runSimulation end" << std::endl;
        }
	}
}
