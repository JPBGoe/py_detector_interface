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

#include <string>

namespace DSIM{
	class ParticleSim : XCSIT::XGeant4ParticleSim{
		public:
			ParticleSim();
			~ParticleSim(); // delete a lot of pointers

			// The following functions are from Tonn Rueter's class
			// ParticleSimulation of the project xdsp. They have been modified
			// only by removing all the karabo dependencies, methods and
			// functions
			void initialization(std::string detectorname);
			void setDetector(std::string detectorname);

		private:
			XCSIT::XGeant4ParticleSim simulator;
    };
}

#endif
