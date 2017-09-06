/*
 *  Element storing a charge
 *
 * File:	ChargeEntry.hh
 * Author:	jburchert
 * Date:	15 August 2017
 */

#ifndef CHARGEENTRY_HH
#define CHARGEENTRY_HH

#include "XChargeEntry.hh"
#include <string>
#include <iostream>

#ifdef DEBUGMODE
    #define DEBUG 1
#else
    #define DEBUG 0
#endif

namespace DSIM {
    /**
     * Instances of this class store a value representing a charge
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
		virtual ~ChargeEntry();

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


        /**
         * @return a string representation of the current state of this instance
         */
        virtual std::string toString();

	private:
		double charge;
	};
}

#endif
