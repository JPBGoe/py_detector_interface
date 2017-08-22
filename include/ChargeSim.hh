/* 
 * File:   	ChargeSim.hh
 * Author: 	jburchert
 * Adapted from: trueter ChargeSimulation.hh
 * 	(without karabo stuff)
 * Date:	14 August 2017	
 */

#ifndef CHARGESIM_HH
#define	CHARGESIM_HH


#include "XPlasmaPointChargeSim.hh"
#include <boost/shared_ptr.hpp>
#include <string>

namespace DSIM {

class ChargeSim : public XCSIT::XPlasmaPointChargeSim {
   
	public:
    	ChargeSim();
    	virtual ~ChargeSim();

		virtual void setInput(boost::shared_ptr<XCSIT::XInteractionData> input);

		// Charge simulation requires certain models. With this function those
		// models in form of interface implementations are bound to the
		// interface
		void setComponents(boost::shared_ptr<XCSIT::XChargeData> output,std::string plasmasearch,std::string pointsim, std::string plasmasim, std::string module);
		void runSimulation();

	private:
		void selectModule(boost::shared_ptr<XCSIT::XChargeData> output,std::string module);
		void selectPlasmaSearch(std::string plasmasearch);
		void selectPlasmaSim(std::string plasmasim);
		void selectPointSim(std::string pointsim);

		// the options that need to be implemented at least as well as an
		// exception if the input string is not in one of them
		const std::string detectorType[5] = {"pnCCD","LPD","AGIPD","AGIPDSPB","CadDummy"};
		const std::string plasmaSim[1] = {"BLANKPLASMA"};
		const std::string plasmaSearch[1] = {"BLANK"};
		const std::string chargeSim[4] = {"FULL","FANO","LUT","BINNING"};
	};

}

#endif
