/*
 * File:   	ChargeMatrix_ext.cc
 * Author: 	jburchert
 * Date:	16 August 2017
 */

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include <boost/python/init.hpp>
#include "ChargeMatrix.hh"
#include "ChargeEntry.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(ChargeMatrix_ext){
	class_<XCSIT::XChargeData, boost::shared_ptr<XCSIT::XChargeData>, boost::noncopyable>("XChargeData", no_init);	

    class_<DSIM::ChargeMatrix, boost::shared_ptr<DSIM::ChargeMatrix>, bases<XCSIT::XChargeData> >("ChargeMatrix", init<>())
		.def("setSize",&DSIM::ChargeMatrix::setSize)
		.def("getEntry",&DSIM::ChargeMatrix::getPyEntry)
		.def("width",&DSIM::ChargeMatrix::width)
		.def("height",&DSIM::ChargeMatrix::height)
		.def("clear",&DSIM::ChargeMatrix::clear)
    ;
	
	register_ptr_to_python<boost::shared_ptr<DSIM::ChargeEntry> >();	
	register_ptr_to_python<boost::shared_ptr<XCSIT::XChargeData> >();	
}
