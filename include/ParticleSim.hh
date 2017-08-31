/*
 * Instances of this class provide an easy access to the
 * XCSIT::XGeant4ParticleSim class since it uses defaults to setup the
 * dettector.
 *
 * File: 	ParticleSim.hh
 * Author:	jburchert
 * Date:	10 August 2017
 */

#ifndef PARTICLESIM_HH
#define PARTICLESIM_HH


#include "XGeant4ParticleSim.hh"
#include "XPrimaryGeneratorAction.hh"

#include "XDetectorConstruction.hh"
#include "LPDDetectorConstruction.hh"
#include "PNCCDDetectorConstruction.hh"
#include "AGIPDDetectorConstruction.hh"
#include "AGIPDSPBDetectorConstruction.hh"
#include "CadDetectorConstruction.hh"

#include "XPhysicsList.hh"
#include "XEventAction.hh"
#include "XParticleSim.hh"

#include "XPhotonData.hh"
#include "XInteractionData.hh"

#include <string>

#include "Constants.hh"
#include <iostream>


namespace DSIM{
    /**
     * Instances of this class perfom simulation of the interaction of photons
     * with the detector
     */
	class ParticleSim : public XCSIT::XGeant4ParticleSim, public DSIM::Constants{
		public:
            /**
             * Constructor
             */
			ParticleSim();
            /**
             * Destructor
             */
			virtual ~ParticleSim(); // delete a lot of pointers

			// The following functions are from Tonn Rueter's class
			// ParticleSimulation of the project xdsp. They have been modified
			// only by removing all the karabo dependencies, methods and
			// functions
			/**
             * Set up the simulation
             * @param detectorname the type of the used detector 
             */
			virtual void initialization(std::string detectorname);

            /**
             * Run the simulation
             * @param input container instance that contain the photons
             * @param output container instance that will contain the
             * interactions with the detector after calculation
             */
			virtual void runSimulation(boost::shared_ptr<XCSIT::XPhotonData> input, boost::shared_ptr<XCSIT::XInteractionData> output);

		private:
    	//	const std::string detectorType[5] = {"pnCCD","LPD","AGIPD","AGIPDSPB","CAD"};
			void setDetector(std::string detectorname);
    };
}

#endif
