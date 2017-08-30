/*
 * File:	ChargeEntry.cc
 * Author:	jburchert
 * Date:	15 August 2017
 */

#include "ChargeEntry.hh"
#include <sstream>

namespace DSIM {

	ChargeEntry::ChargeEntry(){
		charge = 0.0;
	}

	ChargeEntry::~ChargeEntry(){
	}

	double ChargeEntry::getCharge(){
		return charge;
	}

	void ChargeEntry::setCharge(double value){
		charge = value;
	}

	void ChargeEntry::addCharge(double value){
		charge += value;
	}

    std::string ChargeEntry::toString(){
        std::stringstream ss;
        ss << "ChargeEntry: q=" << charge; 
        return ss.str();
    } 

}
