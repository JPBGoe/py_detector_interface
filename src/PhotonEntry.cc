/*
 * Implementation of the methods and functions declared in DSIM::PhotonEntry.hh and
 * XCSIT::XPhotonEntry.hh
 *
 * File:   PhotonEntry.cc
 * Author: jburchert
 *
 * Created on 9 August 2017
 */

#include "PhotonEntry.hh"

namespace DSIM {

    PhotonEntry::PhotonEntry() : XCSIT::XPhotonEntry(){
		// Initialization with 0.0
		Pos = std::vector<double>(3);
		Imp = std::vector<double>(3);
		E = 0;
    }

    PhotonEntry::~PhotonEntry(){
    }

    // Getter
    double DSIM::PhotonEntry::getPositionX(){
		return Pos[0];
    }

    double PhotonEntry::getPositionY(){
		return Pos[1];
    }

    double PhotonEntry::getPositionZ(){
		return Pos[2];
    }

    double PhotonEntry::getDirectionX(){
		return Imp[0];
    }

    double PhotonEntry::getDirectionY(){
		return Imp[1];
    }

    double PhotonEntry::getDirectionZ(){
		return Imp[2];
    }

    double PhotonEntry::getEnergy(){
		return E;
    }


    // Setter
    void PhotonEntry::setPositionX(double value){
		Pos[0] = value;
    }

    void PhotonEntry::setPositionY(double value){
 		Pos[1] = value;
    }

    void PhotonEntry::setPositionZ(double value){
 		Pos[2] = value;
    }

    void PhotonEntry::setDirectionX(double value){
		Imp[0] = value;
    }

    void PhotonEntry::setDirectionY(double value){
		Imp[1] = value;
    }

    void PhotonEntry::setDirectionZ(double value){
		Imp[2] = value;
    }

    void PhotonEntry::setEnergy(double value){
		E = value;
    }

    void PhotonEntry::set(double energy, double dirX, double dirY, double dirZ, double posX, double posY, double posZ){
		setEnergy(energy);
		setDirectionX(dirX);
		setDirectionY(dirY);
		setDirectionZ(dirZ);
		setPositionX(posX);
		setPositionY(posY);
		setPositionZ(posZ);
     }
}
