/*
 * The instances of this class store the data of a single photon of the 
 * simulation. They allowes access to the position in space (Cartesian
 * coordinates) and its impuls as well as the energy of the photon.
 *
 * Functions are set to virtual to allow binding during runtime
 *
 * TODO: Check if the impuls values are the real numbers or if Direction[X|Y|Z] is 
 * just an to one normalized vector pointing in the direction of flight.
 *
 * File:	PhotonEntry.hh
 * Author:	jburchert
 * Date:	9 August 2017
 */
#ifndef PHOTONENTRY_HH
#define PHOTONENTRY_HH

#include "XPhotonEntry.hh"
#include <vector>
#include <string>
#include <iostream>

#ifdef DEBUGMODE
    #define DEBUG 1
#else
    #define DEBUG 0
#endif

namespace DSIM {
    /**
     * Instances of this class store date of the position in space,
     * the directon and the energy of an photon
     */
    class PhotonEntry : public XCSIT::XPhotonEntry{

    public:
        /**
         * Constructor: Initilaization of the private attributes of this class
         */
    	PhotonEntry();
        /**
         * Destructor: No acton
         */
    	~PhotonEntry();
    
	    // Implementation of the functions declared in XPhotonEntry.hh	
	    /**
         * @return the positon of the photon in x
         */
        virtual double getPositionX();
        /**
         * @return the position of the photon in y
         */
	    virtual double getPositionY();
        /**
         * @return the position of photon in z
         */
	    virtual double getPositionZ();
        /**
         * @return the x component of the direction of movement of the photon
         */
	    virtual double getDirectionX();
        /**
         *  @return the y component of the direction of movement of the photon
         */
	    virtual double getDirectionY();
        /**
         *  @return the z component of the direction of movement of the photon
         */
	    virtual double getDirectionZ();
        /**
         * @return the total energy of the photon
         */ 
	    virtual double getEnergy();

	    // Implementaiton of the methods declared in XPhotonEntry.hh
	    /**
         * @param value Sets the photon x position in space
         */
	    virtual void setPositionX(double value);
        /**
         * @param value Sets the photon y position in space
         */
	    virtual void setPositionY(double value);
        /**
         * @param value Sets the photon y position in space
         */
	    virtual void setPositionZ(double value);
        /**
         * @param value Sets the x component of the direction of movement of the
         * photon
         */
	    virtual void setDirectionX(double value);
        /**
         * @param value Sets the y component of the direction of movement of the
         * photon
         */
	    virtual void setDirectionY(double value);
        /**
         * @param value Sets the z component of the direction of movement of the
         * photon
         */
	    virtual void setDirectionZ(double value);
        /**
         * @param value Sets the total energy of the photon
         */
	    virtual void setEnergy(double value);
        /** 
         * @param energy the total energy of the photon: E = cp = c h/lambda
         * @param dirX  the x component of the direction of movement
         * @param dirY  the y component of the direction of movement
         * @param dirZ  the z component of the direction of movement
         * @param posX  the x component of the position in space
         * @param posY  the y component of the position in space
         * @param posZ  the z component of the position in space 
         */
	    virtual void set(double energy, double dirX, double dirY, double dirZ, double posX, double posY, double posZ);
        /**
         * @return a string representation of the current state of this instance
         */
        virtual std::string toString();

    private:
	    // Variables to store the state of a photon
   	    std::vector<double> Pos;
   	    std::vector<double> Imp;
   	    double E;
    };
}

#endif
