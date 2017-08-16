/*
 * File:	ChargeEntry.hh
 * Author:	jburchert
 * Date:	15 August 2017
 */

#ifndef CHARGEENTRY_HH
#define CHARGEENTRY_HH

#include "XChargeEntry.hh"

namespace DSIM {

	class ChargeEntry : public XCSIT::XChargeEntry{
	public:
		ChargeEntry();
		~ChargeEntry();

		virtual double getCharge();
		virtual void setCharge(double value);
		virtual void addCharge(double value);

	private:
		double charge;
	};
}

#endif
