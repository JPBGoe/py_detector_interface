/*
 * File:   	ChargeMatrix_ext.cc
 * Author: 	jburchert
 * Date:	16 August 2017
 */

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include "ChargeMatrix.hh"
#include "ChargeEntry.hh"

BOOST_PYTHON_MODULE(ChargeMatrix_ext){

    boost::python::class_<DSIM::ChargeMatrix>("ChargeMatrix")
		.def("setSize",&DSIM::ChargeMatrix::setSize)
		.def("getEntry",&DSIM::ChargeMatrix::getPyEntry)
		.def("width",&DSIM::ChargeMatrix::width)
		.def("height",&DSIM::ChargeMatrix::height)
		.def("clear",&DSIM::ChargeMatrix::clear)
    ;
	
	boost::python::register_ptr_to_python<boost::shared_ptr<DSIM::ChargeEntry> >();	
}
