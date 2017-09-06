/*
 * After compilation c++ classes are accessable from python.
 * 
 * File:   	InteractionEntry_ext.cc
 * Author: 	jburchert
 * Date:	9 August 2017
 */

#include <boost/python.hpp>
#include "InteractionEntry.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(InteractionEntry_ext){
    class_<XCSIT::XInteractionEntry,boost::noncopyable>("XInteractionEntry", no_init);    

    class_<DSIM::InteractionEntry, bases<XCSIT::XInteractionEntry> >("InteractionEntry")
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
