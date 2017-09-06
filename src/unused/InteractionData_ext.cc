/*
 * File:   InteractionData_ext.cc
 * Author: jburchert
 *
 * Created on 10 August 2017
 */
#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include <boost/python/init.hpp>
#include "InteractionData.hh"
#include "InteractionEntry.hh"


using namespace boost::python;

BOOST_PYTHON_MODULE(InteractionData_ext){
	class_<XCSIT::XInteractionData, boost::shared_ptr<XCSIT::XInteractionData>, boost::noncopyable >("XInteractionData", no_init);

    class_<DSIM::InteractionData, boost::shared_ptr<DSIM::InteractionData>, bases<XCSIT::XInteractionData> >("InteractionData", init<>())
		.def("getEntry",&DSIM::InteractionData::getPyEntry)
		.def("addEntry",&DSIM::InteractionData::addPyEntry)
		.def("size",&DSIM::InteractionData::size)
		.def("clear",&DSIM::InteractionData::clear)
    ;

	register_ptr_to_python<boost::shared_ptr<DSIM::InteractionEntry> >();
}
