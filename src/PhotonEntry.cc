/*
 * Implementation of the methods and functions declared in DSIM::PhotonEntry.hh and
 * XCSIT::XPhotonEntry.hh
 *
 * File:   	PhotonEntry.cc
 * Author: 	jburchert
 * Date:	9 August 2017
 */

#include "PhotonEntry.hh"
#include <sstream>


namespace DSIM {

    PhotonEntry::PhotonEntry(){
        if(DEBUG){
            std::cout << "PhotonEntry::PhotonEntry" << std::endl;
        }
		// Initialization with 0.0
		Pos = std::vector<double>(3);
		Imp = std::vector<double>(3);
		E = 0;
    }

    PhotonEntry::~PhotonEntry(){
        if(DEBUG){
            std::cout << "PhotonEntry::~PhotonEntry" << std::endl;
        }
    }

    // Getter
    double DSIM::PhotonEntry::getPositionX(){
        if(DEBUG){
            std::cout << "PhotonEntry::getPositionX >> " << Pos[0] << std::endl;
        }
		return Pos[0];
    }

    double PhotonEntry::getPositionY(){
        if(DEBUG){
            std::cout << "PhotonEntry::getPositionY >> " << Pos[1] << std::endl;
        }
		return Pos[1];
    }

    double PhotonEntry::getPositionZ(){
        if(DEBUG){
            std::cout << "PhotonEntry::getPositionZ >> " << Pos[2] << std::endl;
        }
		return Pos[2];
    }

    double PhotonEntry::getDirectionX(){
        if(DEBUG){
            std::cout << "PhotonEntry::getDirectionX >> " << Imp[0] << std::endl;
        }
		return Imp[0];
    }

    double PhotonEntry::getDirectionY(){
        if(DEBUG){
            std::cout << "PhotonEntry::getDirectionY >> " << Imp[1] << std::endl;
        }
		return Imp[1];
    }

    double PhotonEntry::getDirectionZ(){
        if(DEBUG){
            std::cout << "PhotonEntry::getDirectionZ >> " << Imp[2] << std::endl;
        }
		return Imp[2];
    }

    double PhotonEntry::getEnergy(){
        if(DEBUG){
            std::cout << "PhotonEntry::getEnergy >> " << E << std::endl;
        }
		return E;
    }


    // Setter
    void PhotonEntry::setPositionX(double value){
        if(DEBUG){
            std::cout << "PhotonEntry::setPositonX << " << value << std::endl;
        }
		Pos[0] = value;
    }

    void PhotonEntry::setPositionY(double value){
        if(DEBUG){
            std::cout << "PhotonEntry::setPositonY << " << value << std::endl;
        }
 		Pos[1] = value;
    }

    void PhotonEntry::setPositionZ(double value){
        if(DEBUG){
            std::cout << "PhotonEntry::setPositonZ << " << value << std::endl;
        }
 		Pos[2] = value;
    }

    void PhotonEntry::setDirectionX(double value){
        if(DEBUG){
            std::cout << "PhotonEntry::setDirectionX << " << value << std::endl;
        }
		Imp[0] = value;
    }

    void PhotonEntry::setDirectionY(double value){
        if(DEBUG){
            std::cout << "PhotonEntry::setDirectionY << " << value << std::endl;
        }
		Imp[1] = value;
    }

    void PhotonEntry::setDirectionZ(double value){
        if(DEBUG){
            std::cout << "PhotonEntry::setDirectionZ << " << value << std::endl;
        }
		Imp[2] = value;
    }

    void PhotonEntry::setEnergy(double value){
        if(DEBUG){
            std::cout << "PhotonEntry::setEnergy << " << value << std::endl;
        }
		E = value;
    }

    void PhotonEntry::set(double energy, double dirX, double dirY, double dirZ, double posX, double posY, double posZ){
        if(DEBUG){
            std::cout << "PhotonEntry::set" << std::endl;
        }
		setEnergy(energy);
		setDirectionX(dirX);
		setDirectionY(dirY);
		setDirectionZ(dirZ);
		setPositionX(posX);
		setPositionY(posY);
		setPositionZ(posZ);
     }

    std::string PhotonEntry::toString(){
        std::stringstream ss;
        ss << "PhotonEntry: Pos=(" << Pos[0] << "," << Pos[1] << "," << Pos[2] << "),Imp=(" << Imp[0] << "," << Imp[1] << "," << Imp[2] << "),E=" << E;
        return ss.str();
    }   
}
