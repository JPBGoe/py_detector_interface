/*
 * File:   InteractionData_ext.cc
 * Author: jburchert
 *
 * Created on 10 August 2017
 */

#include "InteractionData.hh"
#include "InteractionEntry.hh"
#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(InteractionData_ext){
    boost::python::class_<DSIM::InteractionData>("InteractionData")
		.def("getEntry",&DSIM::InteractionData::getEntry)
		.def("addEntry",&DSIM::InteractionData::addEntry)
		.def("size",&DSIM::InteractionData::size)
		.def("clear",&DSIM::InteractionData::clear)
    ;
}
