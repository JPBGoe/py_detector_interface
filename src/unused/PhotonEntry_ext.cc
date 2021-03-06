/*
 * Export the functions from the interface to a python module
 *
 * File:   	PhotonEntry_ext.cc
 * Author: 	jburchert
 * Date:	9 August 2017
 */

#include <boost/python.hpp>
#include "PhotonEntry.hh"

using namespace boost::python;

/**
 * Creation of a python module of class DSIM::PhotonEntry
 * All the functions form the interface are exported
 */
BOOST_PYTHON_MODULE(PhotonEntry_ext){
    class_<XCSIT::XPhotonEntry,boost::noncopyable>("XPhotonEntry", no_init);

    class_<DSIM::PhotonEntry,bases<XCSIT::XPhotonEntry> >("PhotonEntry")
		.def("getPositionX",&DSIM::PhotonEntry::getPositionX)
		.def("getPositionY",&DSIM::PhotonEntry::getPositionY)
		.def("getPositionZ",&DSIM::PhotonEntry::getPositionZ)
		.def("getDirectionX",&DSIM::PhotonEntry::getDirectionX)
		.def("getDirectionY",&DSIM::PhotonEntry::getDirectionY)
		.def("getDirectionZ",&DSIM::PhotonEntry::getDirectionZ)
		.def("getEnergy",&DSIM::PhotonEntry::getEnergy)
		.def("setPositionX",&DSIM::PhotonEntry::setPositionX)
		.def("setPositionY",&DSIM::PhotonEntry::setPositionY)
		.def("setPositionZ",&DSIM::PhotonEntry::setPositionZ)
		.def("setDirectionX",&DSIM::PhotonEntry::setDirectionX)
		.def("setDirectionY",&DSIM::PhotonEntry::setDirectionY)
		.def("setDirectionZ",&DSIM::PhotonEntry::setDirectionZ)
		.def("setEnergy",&DSIM::PhotonEntry::setEnergy)
		.def("set",&DSIM::PhotonEntry::set)
    ;
}
