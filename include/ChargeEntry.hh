/*
 * File:	ChargeEntry.hh
 * Author:	jburchert
 * Date:	15 August 2017
 */

#ifndef CHARGEENTRY_HH
#define CHARGEENTRY_HH

#include "XChargeEntry.hh"

namespace DSIM {
/**
 * Class to implement XCSIT::XChargeEntry of the xcsit software
 * An instance stores a value for a charge
 */ 
	class ChargeEntry : public XCSIT::XChargeEntry{
	public:
        /**
         * Constructor
         */
		ChargeEntry();
        /**
         * Destructor
         */ 
		~ChargeEntry();

        /**
         * @return the charge currently saved in this instance
         */
		virtual double getCharge();
        /**
         * @param value the charge set to this instance
         */
		virtual void setCharge(double value);
        /**
         * @param value charge to be added to the curent charge value of this
         * instance:  newcharge = getCharge() + value
         */
		virtual void addCharge(double value);

	private:
		double charge;
	};
}

#endif
