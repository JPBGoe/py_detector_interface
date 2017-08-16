/*
 * File:   	PhotonData_ext.cc
 * Author: 	jburchert
 * Date:	10 August 2017
 */

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include "PhotonData.hh"
#include "PhotonEntry.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(PhotonData_ext){

    boost::python::class_<DSIM::PhotonData>("PhotonData")
		.def("getEntry",&DSIM::PhotonData::getPyEntry)
		.def("addEntry",&DSIM::PhotonData::addPyEntry)
		.def("size",&DSIM::PhotonData::size)
		.def("clear",&DSIM::PhotonData::clear)
    ;
	
	boost::python::register_ptr_to_python<boost::shared_ptr<DSIM::PhotonEntry> >();	
}
