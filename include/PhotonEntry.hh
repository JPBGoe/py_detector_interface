/*
 * File:	PhotonEntry.hh
 * Author:	jburchert
 *
 * Created on 9 August 2017, 09:09
 */
#ifndef PHOTONENTRY_HH
#define PHOTONENTRY_HH

#include <XPhotonEntry.hh>
#include <vector>
#include <iostream>

namespace DSIM {

    class PhotonEntry : public XCSIT::XPhotonEntry{

    public:
    	PhotonEntry();
    	~PhotonEntry();
    	
	double getPositionX();
	double getPositionY();
	double getPositionZ();
	double getDirectionX();
	double getDirectionY();
	double getDirectionZ();
	double getEnergy();

	void setPositionX(double value);
	void setPositionY(double value);
	void setPositionZ(double value);
	void setDirectionX(double value);
	void setDirectionY(double value);
	void setDirectionZ(double value);
	void setEnergy(double value);
	void set(double energy, double dirX, double dirY, double dirZ, double posX, double posY, double posZ);

    private:
   	std::vector<double> Pos = std::vector<double>(3);
   	std::vector<double> Imp = std::vector<double>(3);
   	double E;
    };
}

#endif
