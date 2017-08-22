/*
 * File:   	ParticleSim_ext.cc
 * Author: 	jburchert
 * Date:	11 August 2017
 */

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include "ParticleSim.hh"
#include "PhotonEntry.hh"

BOOST_PYTHON_MODULE(ParticleSim_ext){
    boost::python::class_<DSIM::ParticleSim>("ParticleSim")
		.def("runSimulation",&DSIM::ParticleSim::runSimulation)
		.def("initialization",&DSIM::ParticleSim::initialization)
    ;
}
