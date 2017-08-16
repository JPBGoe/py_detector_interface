/*
 * File:   	InteractionData.cc
 * Author: 	jburchert
 * Date:	10 August 2017
 */

#include "InteractionData.hh"
#include <stdexcept>

namespace DSIM {

    InteractionData::InteractionData(){
		// clear init
		clear();
    }

    InteractionData::~InteractionData(){
    }

	boost::shared_ptr<XCSIT::XInteractionEntry> InteractionData::getEntry(size_t entry){
		return getPyEntry(entry);
	}

    boost::shared_ptr<XCSIT::XInteractionEntry> InteractionData::addEntry(){
		return addPyEntry();
	}



	boost::shared_ptr<InteractionEntry> InteractionData::getPyEntry(size_t entry){
		if(entry < 0 || entry >= iaNum){
			throw std::invalid_argument("value does not fit to number of elements in this instance");
		}

		return iaVec[entry];
	}


    boost::shared_ptr<InteractionEntry> InteractionData::addPyEntry(){
		// Create the new instance
		// smart pointer will deal with the Destructor call if necessary
		boost::shared_ptr<InteractionEntry> ne(new InteractionEntry());

		// Add it to the vector at the end of the of the ArrayList
		iaVec.push_back(ne);

		iaNum++;
		
		// Return the created instance
		return ne;
	}

    size_t InteractionData::size() const {
		return iaNum;
	}

	// Clears the structure and sets its size to 0, the shared_ptr will deal
	// with calling the Destructor of the contained instances
    void InteractionData::clear(){
		iaVec.clear();
		iaVec.resize(0);
		iaNum = 0;
	}

}
