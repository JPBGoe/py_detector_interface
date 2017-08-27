/*
 * This file stores the data of a single photon interacting with the detector and 
 * deposits a certain amout of energy at a given site at a given time. Access to 
 * the Cartesian coordinates, the energy and the time of interaction with the 
 * detector can be accessed via getter and setter methods and functions. Functions
 * and methods are defined in XCSIT::XInteractionEntry.hh.
 *
 * File:	InteractionEntry.hh
 * Author:	jburchert
 * Data:	9 August 2017
 */
#ifndef INTERACTIONENTRY_HH
#define INTERACTIONENTRY_HH

#include "XInteractionEntry.hh"
#include <vector>

namespace DSIM {

    class InteractionEntry : public XCSIT::XInteractionEntry{

    public:
    	InteractionEntry();
    	~InteractionEntry();
    
		// Implementation of the functions declared in XInteractionEntry.hh	
		virtual double getPositionX();
		virtual double getPositionY();
		virtual double getPositionZ();
		virtual double getEnergy();
		virtual double getTime();

		// Implementaiton of the methods declared in XInteractionEntry.hh
		virtual void setPositionX(double value);
		virtual void setPositionY(double value);
		virtual void setPositionZ(double value);
		virtual void setEnergy(double value);
		virtual void setTime(double value);
		virtual void set(double energy, double time, double posX, double posY, double posZ);

    private:
		// Varaibles to store the state of a photon
   		std::vector<double> Pos;
   		double E;
		double T;
    };
}

#endif
