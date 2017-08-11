/*
 * File:   	ParticleSim_ext.cc
 * Author: 	jburchert
 * Date:	11 August 2017
 */

#include "ParticleSim.hh"
#include "PhotonEntry.hh"
#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>

BOOST_PYTHON_MODULE(ParticleSimt_ext){
    boost::python::class_<DSIM::ParticleSim>("ParticleSim")
		.def("runSimulation",&DSIM::ParticleSim::runSimulation)
		.def("initialization",&DSIM::ParticleSim::initialization)
    ;
}
