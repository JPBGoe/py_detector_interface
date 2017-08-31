/* 
 * File:   	ChargeSim.hh
 * Author: 	jburchert
 * Date:	14 August 2017
 *
 * Adapted from: trueter XCSIT::ChargeSimulation.hh
 * 	(without karabo stuff)
 */

#ifndef CHARGESIM_HH
#define	CHARGESIM_HH


#include "XPlasmaPointChargeSim.hh"
#include <boost/shared_ptr.hpp>
#include <string>

#include "Constants.hh"
#include <iostream>

namespace DSIM {

    /**
     * Instances of this class performe the charge simulation after the charge
     *  is created by the photon detector interaction on its way to the 
     *  readout electronics
     */
    class ChargeSim : public XCSIT::XPlasmaPointChargeSim, public DSIM::Constants {
   
	    public:
            /**
             * Constructor
             */
    	    ChargeSim();
            /**
             * Destructor
             */
    	    virtual ~ChargeSim();

            /**
             * @param input The input to the simulation consists of the storage
             * container, containing elements that store interactions of
             * elements with the detector
             */
		    virtual void setInput(boost::shared_ptr<XCSIT::XInteractionData> input);

    		// Charge simulation requires certain models. With this function those
    		// models in form of interface implementations are bound to the
    		// interface
    		/**
             * Specify the details of the executed simulation.
             * @param output the container to where the output data should be
             * written to
             * @param plasmasearch the plasma search method
             * @param pointsim the charge propagation model
             * @param plasmasim
             * @param detector the detector type
             */
    		virtual void setComponents(std::string plasmasearch,std::string pointsim, std::string plasmasim, std::string detector);
            /**
             * Run the simulation
             */
    		virtual void runSimulation();

            /**
             * Due to the missing setSize option in XChargeData it is necessary
             * to create the ChargeMatrix instance in setComponents (also due to
             * the detector size
             * @return the created charge matrix
             */
            virtual boost::shared_ptr<XCSIT::XChargeData> getOutput();

    	private:
            boost::shared_ptr<ChargeMatrix> output;

            // Set the elements of the simulation and check if they are
            // specified in the fields below
    		virtual void selectDetector(std::string detector);
    		virtual void selectPlasmaSearch(std::string plasmasearch);
    		virtual void selectPlasmaSim(std::string plasmasim);
    		virtual void selectPointSim(std::string pointsim);
    
    		// the options that need to be implemented at least as well as an
    		// exception if the input string is not in one of them
    		//const std::string detectorType[5] = {"pnCCD","LPD","AGIPD","AGIPDSPB","CAD"};
    		//const std::string plasmaSim[1] = {"BLANKPLASMA"};
    		//const std::string plasmaSearch[1] = {"BLANK"};
    		//const std::string chargeSim[4] = {"FULL","FANO","LUT","BINNING"};
	};

}

#endif
