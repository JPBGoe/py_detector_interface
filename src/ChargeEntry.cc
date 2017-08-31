/*
 * File:	ChargeEntry.cc
 * Author:	jburchert
 * Date:	15 August 2017
 */

#include "ChargeEntry.hh"
#include <sstream>

namespace DSIM {

	ChargeEntry::ChargeEntry(){
        if(DEBUG){
            std::cout << "ChargeEntry::ChargeEntry" << std::endl;
        }
		charge = 0.0;
	}

	ChargeEntry::~ChargeEntry(){
        if(DEBUG){
            std::cout << "ChargeEntry::ChargeEntry" << std::endl;
        }
	}

	double ChargeEntry::getCharge(){
        if(DEBUG){
            std::cout << "ChargeEntry::getCharge >> " << charge << std::endl;
        }
		return charge;
	}

	void ChargeEntry::setCharge(double value){
        if(DEBUG){
            std::cout << "ChargeEntry::setCharge << " << value << std::endl;
        }
		charge = value;
	}

	void ChargeEntry::addCharge(double value){
        if(DEBUG){
            std::cout << "ChargeEntry::addCharge << " << value << std::endl;
        }
		charge += value;
	}

    std::string ChargeEntry::toString(){
        std::stringstream ss;
        ss << "ChargeEntry: q=" << charge; 
        return ss.str();
    } 

}
