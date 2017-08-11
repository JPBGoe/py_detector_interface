/*
 * File: 	ChargeSim.hh
 * Author:	jburchert
 * Date:	11 August 2017
 */

#ifndef CHARGESIM_HH
#define CHARGESIM_HH

#include "XChargeSim.hh"
#include <string>

namespace DSIM {
	class ChargeSim : public XCSIT::XChargeSim{
		public:
			ChargeSim();
			ChargeSim(boost::shared_ptr<XInteractionData> input, boost::shared_prt<XChargeData> outpu) : XChargeSim(input,output)
			~ChargeSim();

			void setInput(boost::shared_ptr<XInteractionData> input);
			void setOutput(boost::shared_prt<XChargeData> output);
			void runSimulation();
			void runSimulation(boost::shared_ptr<XInteractionData> input, boost::shared_prt<XChargeData> output);
		
			// Following functions are located in tonn rueter's class
			// ChargeSimulation in th xdsp package
			void initialization();
			void configureChargeSimulation();
			void setModuleDefinition(std::string modulename);
			void setChargeSimulation(std::string chargesimname);

	};
}
#endif
