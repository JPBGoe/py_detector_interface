/*
 * File:   	ChargeMatrix_ext.cc
 * Author: 	jburchert
 * Date:	11 August 2017
 */

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include "XChargeMatrix.hh"

BOOST_PYTHON_MODULE(XChargeMatrix_ext){
	boost::python::class_<XCSIT::XChargeMatrix>("XChargeMatrix")
   /* boost::python::class_<XCSIT::XChargeMatrix>("XChargeMatrix",boost::python::init<size_t,size_t>())
		.def(boost::python::init<>())
		.def("getEntry",&XCSIT::XChargeMatrix::getEntry)
		.def("width",&XCSIT::XChargeMatrix::width)
		.def("height",&XCSIT::XChargeMatrix::height)
		.def("reset",&XCSIT::XChargeMatrix::reset)*/
    ;

//	boost::python::register_ptr_to_python<boost::shared_ptr<XCSIT::XChargeMatrixEntry>>();
}
