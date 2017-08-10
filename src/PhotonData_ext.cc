/*
 * File:   PhotonData_ext.cc
 * Author: jburchert
 *
 * Created on 9 August 2017
 */

#include "PhotonData.hh"
#include "PhotonEntry.hh"
#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(PhotonData_ext){
    boost::python::class_<DSIM::PhotonData>("PhotonData")
		.def("getEntry",&DSIM::PhotonData::getEntry)
		.def("addEntry",&DSIM::PhotonData::addEntry)
		.def("size",&DSIM::PhotonData::size)
		.def("clear",&DSIM::PhotonData::clear)
    ;
}
