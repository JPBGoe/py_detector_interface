/*
 * File:	ChargeSim.cc
 * Author:	jburchert
 * Date:	14 August 2017
 */

#include "ChargeSim.hh"
#include <stdexcept>
#include "ChargeMatrix.hh"

// Modules available in this implementation
#include "PNCCDModuleDefinition.hh" 
#include "LPDModuleDefinition.hh" 
#include "AGIPDModuleDefinition.hh" 
#include "AGIPDSPBModuleDefinition.hh" 
#include "CadDummyModuleDefinition.hh" 

// XCSIT Point charge simulations
#include "XPerfectSingleCharge.hh"
#include "XPointFanoSingleCharge.hh"
#include "XPointSpreadSingleCharge.hh"
#include "XPointSpreadSingleChargeLUT.hh"

// XCSIT Plasma simulations and related classes
#include "XBlankPlasmaSim.hh"
#include "XBlankPlasmaCellSearch.hh"

#include "XChargeData.hh"

namespace DSIM {
    
	ChargeSim::ChargeSim(){
        if(DEBUG){
            std::cout << "ChargeSim::ChargeSim" << std::endl;
        }
	}

	ChargeSim::~ChargeSim(){
        if(DEBUG){
            std::cout << "ChargeSim::~ChargeSim" << std::endl;
        }
	}

	void ChargeSim::setInput(boost::shared_ptr<XCSIT::XInteractionData> input){
	    if(DEBUG){
            std::cout << "ChargeSim::setInput" << std::endl;
        }	
        XCSIT::XPlasmaPointChargeSim::setInput(input);
	}

    void ChargeSim::setOutput(boost::shared_ptr<ChargeMatrix> output){
        if(DEBUG){
            std::cout << "ChargeSim::setOutput" << std::endl;
        }
        this->output = output;
    }


	void ChargeSim::runSimulation(){
 	    if(DEBUG){
            std::cout << "ChargeSim::runSimulation start" << std::endl;
        }
        // XPlasmaPointChargeSim needs to throw if there is something missing
		XCSIT::XPlasmaPointChargeSim::runSimulation();
	    if(DEBUG){
            std::cout << "ChargeSim::runSimulation end" << std::endl;
        }
	}

   /* boost::shared_ptr<ChargeMatrix> ChargeSim::getOutput(){
        return output;
    }*/

	
	void ChargeSim::selectDetector(std::string detector){
		if(DEBUG){
            std::cout << "ChargeSim::selectDetector << " << detector << std::endl;
        }

        // boost shared_ptr returns false if not instantiated
        if(not output){
            throw std::runtime_error("output has to be initialized first");
        }

        // Instantiate the selected model
		boost::shared_ptr<XCSIT::XModuleDefinition> detectordef;
    	if(detector == DetectorType[0]){
        	detectordef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::PNCCDModuleDefinition);
    	}else if(detector == DetectorType[1]){
        	detectordef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::LPDModuleDefinition);
    	}else if(detector == DetectorType[2]){
        	detectordef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::AGIPDModuleDefinition);
    	}else if(detector == DetectorType[3]){
        	detectordef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::AGIPDSPBModuleDefinition);
    	}else if(detector == DetectorType[4]){
        	detectordef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::CadDummyModuleDefinition);
    	}else{
			throw std::invalid_argument("detector model is unknown: " + detector );
    	}

	   	// Resize the output according to the detector
  	  	unsigned int n = (unsigned int) (2. * detectordef->getSizeX() / detectordef->getSpacingX());
    	unsigned int m = (unsigned int) (2. * detectordef->getSizeY() / detectordef->getSpacingY());
       
        // Create a new instance 
        //boost::shared_ptr<ChargeMatrix> out(new ChargeMatrix(n,m)); 
        //output=out;		
        ((this->output).get())->clear();   
        ((this->output).get())->setSize(n,m);   


        // Set the output
        XCSIT::XPlasmaPointChargeSim::setOutput(output);

    
		// Set the component
		XCSIT::XPlasmaPointChargeSim::setDefinition(detectordef);
	}

	void ChargeSim::selectPlasmaSearch(std::string plasmasearch){
		if(DEBUG){
            std::cout << "ChargeSim::selectPlasmaSearch << " << plasmasearch << std::endl;
        }

		// Instantiate the selected model
		boost::shared_ptr<XCSIT::XBlankPlasmaCellSearch> plasmaCellSearch;
		if(plasmasearch == PlasmaSearch[0]){
			plasmaCellSearch = boost::shared_ptr<XCSIT::XBlankPlasmaCellSearch>(new XCSIT::XBlankPlasmaCellSearch);
		}else{
			throw std::invalid_argument("plasma search model is unknown: "+ plasmasearch);
		}

		// Set the component
		XCSIT::XPlasmaPointChargeSim::setPlasmaSearch(plasmaCellSearch);
	}

	void ChargeSim::selectPlasmaSim(std::string plasmasim){
		if(DEBUG){
            std::cout << "ChargeSim::selectPlasmaSim << " << plasmasim << std::endl;
        }

		// Instantiate the selected model
		boost::shared_ptr<XCSIT::XPlasmaChargeSim> plasmaSimulation;
    	if(plasmasim == PlasmaSim[0]){
        	plasmaSimulation = boost::shared_ptr<XCSIT::XBlankPlasmaSim>(new XCSIT::XBlankPlasmaSim);
    	}else{
			throw std::invalid_argument("plasma sim model is unknown: "+ plasmasim);
    	}
    
    	// Set the component
    	XCSIT::XPlasmaPointChargeSim::setPlasmaSim(plasmaSimulation);
	}


	void ChargeSim::selectPointSim(std::string pointsim){
 		if(DEBUG){
            std::cout << "ChargeSim::selectPointSim << " << pointsim << std::endl;
        }       

   		// Instantiate the selected model 
    	if(pointsim == ChargeProp[0]){
			boost::shared_ptr<XCSIT::XPointSpreadSingleCharge> pss(new XCSIT::XPointSpreadSingleCharge);
			XCSIT::XPlasmaPointChargeSim::setPointSim(pss);
		}else if(pointsim == ChargeProp[1]){
			boost::shared_ptr<XCSIT::XPointFanoSingleCharge> pss(new XCSIT::XPointFanoSingleCharge);
			XCSIT::XPlasmaPointChargeSim::setPointSim(pss);
		}else if(pointsim == ChargeProp[2]){
			throw std::invalid_argument("Not supported due to error in XCSIT::XPointSpreadSingleChargeLUT");
			//boost::shared_ptr<XCSIT::XPointSpreadSingleChargeLUT> pss(new XCSIT::XPointSpreadSingleChargeLUT);
			//XCSIT::XPlasmaPointChargeSim::setPointSim(pss);
		}else if(pointsim == ChargeProp[3]){
			boost::shared_ptr<XCSIT::XPerfectSingleCharge> pss(new XCSIT::XPerfectSingleCharge);
			XCSIT::XPlasmaPointChargeSim::setPointSim(pss);
		}else{
			throw std::invalid_argument("point sim model is unknown: " + pointsim);
		}
	}


	// Sets all the necessary components of the simulation except for input and
	// output data
	void ChargeSim::setComponents(std::string plasmasearch,std::string pointsim, std::string plasmasim, std::string detector){
        if(DEBUG){
            std::cout << "ChargeSim::setComponents" << std::endl;
        }

		// plasmasearch method
		selectPlasmaSearch(plasmasearch);

		// the model for the behaviour of a singe charge
		selectPointSim(pointsim);

		// the model for multiple charges
		selectPlasmaSim(plasmasim);

		// the detector
		selectDetector(detector);
	}
}
