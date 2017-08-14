/*
 * File:   	ChargeMatrix_ext.cc
 * Author: 	jburchert
 * Date:	11 August 2017
 */

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include "XChargeMatrix.hh"

using namespace XCSIT;

BOOST_PYTHON_MODULE(ChargeMatrixEntry_ext){
    boost::python::class_<XChargeMatrixEntry>("ChargeMatrixEntry",boost::python::init<size_t,size_t,boost::shared_ptr<XChargeMatrix>>())
		.def("getCharge",&XChargeMatrixEntry::getCharge)
		.def("setCharge",&XChargeMatrixEntry::setCharge)
		.def("addCharge",&XChargeMatrixEntry::addCharge)
    ;
}

BOOST_PYTHON_MODULE(ChargeMatrix_ext){
    boost::python::class_<XChargeMatrix>("ChargeMatrix",boost::python::init<size_t,size_t>())
		.def(boost::python::init<>())
		.def("getEntry",&XChargeMatrix::getEntry)
		.def("width",&XChargeMatrix::width)
		.def("height",&XChargeMatrix::height)
		.def("reset",&XChargeMatrix::reset)
    ;
}
