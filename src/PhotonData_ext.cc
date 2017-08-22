/*
 * File:   	PhotonData_ext.cc
 * Author: 	jburchert
 * Date:	10 August 2017
 */

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include <boost/python/init.hpp>
#include "PhotonData.hh"
#include "PhotonEntry.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(PhotonData_ext){
	class_<XCSIT::XPhotonData, boost::shared_ptr<XCSIT::XPhotonData>, boost::noncopyable>("XPhotonData", no_init);

    class_<DSIM::PhotonData, boost::shared_ptr<DSIM::PhotonData>, bases<XCSIT::XPhotonData> >("PhotonData", init<>())
		.def("getEntry",&DSIM::PhotonData::getPyEntry)
		.def("addEntry",&DSIM::PhotonData::addPyEntry)
		.def("size",&DSIM::PhotonData::size)
		.def("clear",&DSIM::PhotonData::clear)
    ;
	
	register_ptr_to_python<boost::shared_ptr<DSIM::PhotonEntry> >();	
}
