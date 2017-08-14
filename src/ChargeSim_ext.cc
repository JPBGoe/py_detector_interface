/*
 * File:   	ChargeSim_ext.cc
 * Author: 	jburchert
 * Date:	14 August 2017
 */

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include "ChargeSim.hh"
#include "XPlasmaPointChargeSim.hh"

using namespace DSIM;

BOOST_PYTHON_MODULE(ChargeSim_ext){
    boost::python::class_<ChargeSim,boost::python::bases<XCSIT::XPlasmaPointChargeSim>>("ChargeSim")
		.def("setInput",&ChargeSim::setInput)
		.def("setComponents",&ChargeSim::setComponents)
		.def("runSimulation",&ChargeSim::runSimulation)
    ;
}
