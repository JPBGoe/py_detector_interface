/*
 * Implementation of the methods and functions declared in DSIM::InteractionEntry.hh and
 * XCSIT::XInteractionEntry.hh
 *
 * File:   	InteractionEntry.cc
 * Author: 	jburchert
 * Date:	9 August 2017
 */

#include "InteractionEntry.hh"
#include <sstream>

namespace DSIM {

    InteractionEntry::InteractionEntry() : XCSIT::XInteractionEntry(){
		Pos = std::vector<double>(3);
		E = 0;
		T = 0;
    }

    InteractionEntry::~InteractionEntry(){
    }

    // Getter
    double DSIM::InteractionEntry::getPositionX(){
		return Pos[0];
    }

    double InteractionEntry::getPositionY(){
		return Pos[1];
    }

    double InteractionEntry::getPositionZ(){
		return Pos[2];
    }

    double InteractionEntry::getEnergy(){
		return E;
    }

    double InteractionEntry::getTime(){
		return T;
    }


    // Setter
    void InteractionEntry::setPositionX(double value){
		Pos[0] = value;
    }

    void InteractionEntry::setPositionY(double value){
 		Pos[1] = value;
    }

    void InteractionEntry::setPositionZ(double value){
 		Pos[2] = value;
    }

    void InteractionEntry::setEnergy(double value){
		E = value;
    }

    void InteractionEntry::setTime(double value){
		T = value;
    }

    void InteractionEntry::set(double energy, double time, double posX, double posY, double posZ){
		setEnergy(energy);
		setTime(time);
		setPositionX(posX);
		setPositionY(posY);
		setPositionZ(posZ);
	}

    std::string InteractionEntry::toString(){
        std::stringstream ss;
        ss << "InteractionEntry: Pos=(" << Pos[0] << "," << Pos[1] << "," << Pos[2] << "),E=" << E << ",t=" << T << std::endl;
        return ss.str();
    } 


}
