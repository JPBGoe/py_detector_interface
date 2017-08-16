/*
 * File:   InteractionData_ext.cc
 * Author: jburchert
 *
 * Created on 10 August 2017
 */
#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include "InteractionData.hh"
#include "InteractionEntry.hh"


using namespace boost::python;

BOOST_PYTHON_MODULE(InteractionData_ext){
    boost::python::class_<DSIM::InteractionData>("InteractionData")
		.def("getEntry",&DSIM::InteractionData::getPyEntry)
		.def("addEntry",&DSIM::InteractionData::addPyEntry)
		.def("size",&DSIM::InteractionData::size)
		.def("clear",&DSIM::InteractionData::clear)
    ;

	boost::python::register_ptr_to_python<boost::shared_ptr<DSIM::InteractionEntry> >();
}
