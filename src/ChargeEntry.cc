/*
 * File:	ChargeEntry.cc
 * Author:	jburchert
 * Date:	15 August 2017
 */

#include "ChargeEntry.hh"

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
}
