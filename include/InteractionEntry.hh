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

    /**
     * Instances of this call store the information of photons interacting with
     * the detector by depositing their energy at a certain place of the
     * detector at a certain time
     */
    class InteractionEntry : public XCSIT::XInteractionEntry{

    public:
        /**
         *  Constructor: Sets the instance attributes
         */
    	InteractionEntry();
        /**
         * Destuctor
         */
    	virtual ~InteractionEntry();
    
		// Implementation of the functions declared in XInteractionEntry.hh	
		/**
         * @return the x component of the position on the detector where the
         * energy is deposited
         */
		virtual double getPositionX();
		/**
         * @return the y component of the position on the detector where the
         * energy is deposited
         */
		virtual double getPositionY();
		/**
         * @return the z component of the position on the detector where the
         * energy is deposited
         */
		virtual double getPositionZ();
		/**
         * @return the deposited energy at the location
         */
		virtual double getEnergy();
        /**
         * @return the time when the energy was deposied
         */
		virtual double getTime();

		// Implementaiton of the methods declared in XInteractionEntry.hh
		/**
         * @param value the x component of the position where the energy is
         * deposited
         */
		virtual void setPositionX(double value);
		/**
         * @param value the y component of the position where the energy is
         * deposited
         */
		virtual void setPositionY(double value);
		/**
         * @param value the z component of the position where the energy is
         * deposited
         */
		virtual void setPositionZ(double value);
        /**
         * @param value the value of the energy deposited at the specified
         * position of the detector
         */
		virtual void setEnergy(double value);
        /**
         * @param value the time when the energy is deposied
         */
		virtual void setTime(double value);
        /**
         * Combined setting of all the values
         * @param energy the deposited energy
         * @param time the time of deposition
         * @param posX x component of the position
         * @param posY y component of the position
         * @param posZ z component of the position
         */
		virtual void set(double energy, double time, double posX, double posY, double posZ);

    private:
		// Varaibles to store the state of a photon
   		std::vector<double> Pos;
   		double E;
		double T;
    };
}

#endif
