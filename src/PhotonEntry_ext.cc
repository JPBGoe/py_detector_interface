/*
 * File:   PhotonEntry_ext.cc
 * Author: jburchert
 *
 * Created on 9 August 2017
 */

#include "PhotonEntry.hh"
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(PhotonEntry_ext){
    boost::python::class_<DSIM::PhotonEntry>("PhotonEntry")
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
