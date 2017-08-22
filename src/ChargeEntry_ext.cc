/*
 * File:   	ChargeEntry_ext.cc
 * Author: 	jburchert
 * Date:	9 August 2017
 */

#include <boost/python.hpp>
#include "ChargeEntry.hh"

BOOST_PYTHON_MODULE(ChargeEntry_ext){
    boost::python::class_<DSIM::ChargeEntry>("ChargeEntry")
		.def("getCharge",&DSIM::ChargeEntry::getCharge)
		.def("setCharge",&DSIM::ChargeEntry::setCharge)
		.def("addCharge",&DSIM::ChargeEntry::addCharge)
    ;
}
