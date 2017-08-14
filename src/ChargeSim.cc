/*
 * File:	ChargeSim.cc
 * Author:	jburchert
 * Date:	14 August 2017
 */

#include "ChargeSim.hh"
#include <stdexcept>
#include "XChargeMatrix.hh"

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
//#include "XPointSpreadSingleChargeLUT.hh"

// XCSIT Plasma simulations and related classes
#include "XBlankPlasmaSim.hh"
#include "XBlankPlasmaCellSearch.hh"



namespace DSIM {
    
	ChargeSim::ChargeSim(){
	}

	ChargeSim::~ChargeSim(){
	}

	void ChargeSim::setInput(boost::shared_ptr<XCSIT::XInteractionData> input){
		XCSIT::XPlasmaPointChargeSim::setInput(input);
	}


	void ChargeSim::runSimulation(){
		XCSIT::XPlasmaPointChargeSim::runSimulation();
	}

	
	void ChargeSim::selectModule(boost::shared_ptr<XCSIT::XChargeData> output,std::string module){
		// Instantiate the selected model
		boost::shared_ptr<XCSIT::XModuleDefinition> moduledef;
    	if(module == "PNCCD"){
        	moduledef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::PNCCDModuleDefinition);
    	}else if(module == "LPD"){
        	moduledef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::LPDModuleDefinition);
    	}else if(module == "AGIPD"){
        	moduledef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::AGIPDModuleDefinition);
    	}else if(module == "AGIPDSPB"){
        	moduledef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::AGIPDSPBModuleDefinition);
    	}else if(module == "CadDummy"){
        	moduledef = boost::shared_ptr<XCSIT::XModuleDefinition>(new XCSIT::CadDummyModuleDefinition);
    	}else{
			throw std::invalid_argument("module model is unknown");
    	}

	   	// Resize the output according to the module
  	  	unsigned int n = (unsigned int) (2. * moduledef->getSizeX() / moduledef->getSpacingX());
    	unsigned int m = (unsigned int) (2. * moduledef->getSizeY() / moduledef->getSpacingY());
  		output = boost::shared_ptr<XCSIT::XChargeData>(new XCSIT::XChargeMatrix(n, m));
		setOutput(output);

    
		// Set the component
		XCSIT::XPlasmaPointChargeSim::setDefinition(moduledef);
	}

	void ChargeSim::selectPlasmaSearch(std::string plasmasearch){
		// Instantiate the selected model
		boost::shared_ptr<XCSIT::XBlankPlasmaCellSearch> plasmaCellSearch;
		if(plasmasearch == "BLANK"){
			plasmaCellSearch = boost::shared_ptr<XCSIT::XBlankPlasmaCellSearch>(new XCSIT::XBlankPlasmaCellSearch);
		}else{
			throw std::invalid_argument("plasma search model is unknown");
		}

		// Set the component
		XCSIT::XPlasmaPointChargeSim::setPlasmaSearch(plasmaCellSearch);
	}

	void ChargeSim::selectPlasmaSim(std::string plasmasim){
		// Instantiate the selected model
		boost::shared_ptr<XCSIT::XPlasmaChargeSim> plasmaSimulation;
    	if(plasmasim == "BLANKPLASMA"){
        	plasmaSimulation = boost::shared_ptr<XCSIT::XBlankPlasmaSim>(new XCSIT::XBlankPlasmaSim);
    	}else{
			throw std::invalid_argument("plasma sim model is unknown");
    	}
    
    	// Set the component
    	XCSIT::XPlasmaPointChargeSim::setPlasmaSim(plasmaSimulation);
	}


	void ChargeSim::selectPointSim(std::string pointsim){
   		// Instantiate the selected model 
    	if(pointsim == "FULL"){
			boost::shared_ptr<XCSIT::XPointSpreadSingleCharge> pss(new XCSIT::XPointSpreadSingleCharge);
			XCSIT::XPlasmaPointChargeSim::setPointSim(pss);
		}else if(pointsim == "FANO"){
			boost::shared_ptr<XCSIT::XPointFanoSingleCharge> pss(new XCSIT::XPointFanoSingleCharge);
			XCSIT::XPlasmaPointChargeSim::setPointSim(pss);
		}else if(pointsim == "LUT"){
			throw std::invalid_argument("LUT base implementation has errors though not supported here");
			//pss = boost::shared_ptr<XCSIT::XPointSpreadSingleChargeLUT>(new XCSIT::XPointSpreadSingleChargeLUT);
		}else if(pointsim == "BINNING"){
			boost::shared_ptr<XCSIT::XPerfectSingleCharge> pss(new XCSIT::XPerfectSingleCharge);
			XCSIT::XPlasmaPointChargeSim::setPointSim(pss);
		}else{
			throw std::invalid_argument("point sim model is unknown");
		}
	}


	// Sets all the necessary components of the simulation except for input and
	// output data
	void ChargeSim::setComponents(boost::shared_ptr<XCSIT::XChargeData> output,std::string plasmasearch,std::string pointsim, std::string plasmasim, std::string module){
		// plasmasearch method
		selectPlasmaSearch(plasmasearch);

		// the model for the behaviour of a singe charge
		selectPointSim(pointsim);

		// the model for multiple charges
		selectPlasmaSim(plasmasim);

		// the module
		selectModule(output,module);
	}
}
