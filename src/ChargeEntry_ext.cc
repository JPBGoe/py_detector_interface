/*
 * Export the functions from the interface to a python module
 *
 * File:   	ChargeEntry_ext.cc
 * Author: 	jburchert
 * Date:	9 August 2017
 */

#include <boost/python.hpp>
#include "ChargeEntry.hh"

using namespace boost::python;

/**
 * Creation of a python module of class DSIM::ChargeEntry
 * All the functions from the interface are exported
 */
BOOST_PYTHON_MODULE(ChargeEntry_ext){
    class_<XCSIT::XChargeEntry, boost::noncopyable>("XChargeEntry",no_init);

    class_<DSIM::ChargeEntry, bases<XCSIT::XChargeEntry> >("ChargeEntry")
		.def("getCharge",&DSIM::ChargeEntry::getCharge)
		.def("setCharge",&DSIM::ChargeEntry::setCharge)
		.def("addCharge",&DSIM::ChargeEntry::addCharge)
    ;
}
