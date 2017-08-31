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
        if(DEBUG){
            std::cout << "InteractionEntry::InteractionEntry" << std::endl;
        }
		Pos = std::vector<double>(3);
		Energy = 0;
		Time = 0;
    }

    InteractionEntry::~InteractionEntry(){
        if(DEBUG){
            std::cout << "InteractionEntry::~InteractionEntry" << std::endl;
        }
    }

    // Getter
    double DSIM::InteractionEntry::getPositionX(){
        if(DEBUG){
            std::cout << "InteractionEntry::getPositionX >> " << Pos[0] << std::endl;
        }
		return Pos[0];
    }

    double InteractionEntry::getPositionY(){
        if(DEBUG){
            std::cout << "InteractionEntry::getPositionY >> " << Pos[1] << std::endl;
        }
		return Pos[1];
    }

    double InteractionEntry::getPositionZ(){
        if(DEBUG){
            std::cout << "InteractionEntry::getPositionZ >> " << Pos[2] << std::endl;
        }
		return Pos[2];
    }

    double InteractionEntry::getEnergy(){
        if(DEBUG){
            std::cout << "InteractionEntry::Energy >> " << Energy << std::endl;
        }
		return Energy;
    }

    double InteractionEntry::getTime(){
        if(DEBUG){
            std::cout << "InteractionEntry::getTime >> " << Time << std::endl;
        }
		return Time;
    }


    // Setter
    void InteractionEntry::setPositionX(double value){
        if(DEBUG){
            std::cout << "InteractionEntry::setPositionX << " << value << std::endl;
        }
		Pos[0] = value;
    }

    void InteractionEntry::setPositionY(double value){
        if(DEBUG){
            std::cout << "InteractionEntry::setPositionY << " << value << std::endl;
        }
 		Pos[1] = value;
    }

    void InteractionEntry::setPositionZ(double value){
        if(DEBUG){
            std::cout << "InteractionEntry::setPositionZ << " << value << std::endl;
        }
 		Pos[2] = value;
    }

    void InteractionEntry::setEnergy(double value){
        if(DEBUG){
            std::cout << "InteractionEntry::setEnergy << " << value << std::endl;
        }
		Energy = value;
    }

    void InteractionEntry::setTime(double value){
        if(DEBUG){
            std::cout << "InteractionEntry::setTime << " << value << std::endl;
        }
		Time = value;
    }

    void InteractionEntry::set(double energy, double time, double posX, double posY, double posZ){
        if(DEBUG){
            std::cout << "InteractionEntry::set" << std::endl;
        }
		setEnergy(energy);
		setTime(time);
		setPositionX(posX);
		setPositionY(posY);
		setPositionZ(posZ);
	}

    std::string InteractionEntry::toString(){
        std::stringstream ss;
        ss << "InteractionEntry: Pos=(" << Pos[0] << "," << Pos[1] << "," << Pos[2] << "),E=" << Energy << ",t=" << Time << std::endl;
        return ss.str();
    } 


}
