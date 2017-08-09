/*
 * After compilation c++ classes are accessable from python.
 * 
 * File:   InteractionEntry_ext.cc
 * Author: jburchert
 *
 * Created on 9 August 2017
 */

#include "InteractionEntry.hh"
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(InteractionEntry_ext){
boost::python::class_<DSIM::InteractionEntry>("InteractionEntry")
		.def("getPositionX",&DSIM::InteractionEntry::getPositionX)
		.def("getPositionY",&DSIM::InteractionEntry::getPositionY)
		.def("getPositionZ",&DSIM::InteractionEntry::getPositionZ)
		.def("getTime",&DSIM::InteractionEntry::getTime)
		.def("getEnergy",&DSIM::InteractionEntry::getEnergy)
		.def("setPositionX",&DSIM::InteractionEntry::setPositionX)
		.def("setPositionY",&DSIM::InteractionEntry::setPositionY)
		.def("setPositionZ",&DSIM::InteractionEntry::setPositionZ)
		.def("setTime",&DSIM::InteractionEntry::setTime)
		.def("setEnergy",&DSIM::InteractionEntry::setEnergy)
		.def("set",&DSIM::InteractionEntry::set)
	;
}
