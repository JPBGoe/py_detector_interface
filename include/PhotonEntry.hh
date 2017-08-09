/*
 * The instances of this class store the data of a single photon of the 
 * simulation. They allowes access to the position in space (Cartesian
 * coordinates) and its impuls as well as the energy of the photon.
 *
 * TODO: Check if the impuls values are the real numbers or if Direction[X|Y|Z] is 
 * just an to one normalized vector pointing in the direction of flight.
 *
 * File:	PhotonEntry.hh
 * Author:	jburchert
 *
 * Created on 9 August 2017
 */
#ifndef PHOTONENTRY_HH
#define PHOTONENTRY_HH

#include "XPhotonEntry.hh"
#include <vector>

namespace DSIM {

    class PhotonEntry : public XCSIT::XPhotonEntry{

    public:
    	PhotonEntry();
    	~PhotonEntry();
    
	// Implementation of the functions declared in XPhotonEntry.hh	
	double getPositionX();
	double getPositionY();
	double getPositionZ();
	double getDirectionX();
	double getDirectionY();
	double getDirectionZ();
	double getEnergy();

	// Implementaiton of the methods declared in XPhotonEntry.hh
	void setPositionX(double value);
	void setPositionY(double value);
	void setPositionZ(double value);
	void setDirectionX(double value);
	void setDirectionY(double value);
	void setDirectionZ(double value);
	void setEnergy(double value);
	void set(double energy, double dirX, double dirY, double dirZ, double posX, double posY, double posZ);

    private:
	// Variables to store the state of a photon
   	std::vector<double> Pos;
   	std::vector<double> Imp;
   	double E;
    };
}

#endif
