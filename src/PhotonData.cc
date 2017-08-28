/*
 * File:   	PhotonData.cc
 * Author: 	jburchert
 * Date:	10 August 2017
 */

#include "PhotonData.hh"
#include <stdexcept>

namespace DSIM {

    PhotonData::PhotonData():XPhotonData(){
		// initialization
		clear();
    }

    PhotonData::~PhotonData(){
    }

	
	/*boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::getEntry(size_t entry){
		return getPyEntry(entry);
	}

    boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::addEntry(){
		return addPyEntry();
	}*/

	boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::getEntry(size_t entry){
		if(entry < 0 || entry >= photonNum){
			throw std::invalid_argument("value does not fit to number of elements in this instance");
		}

		return photonVec[entry];
	}

    boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::addEntry(){
		// Create the new instance
		// smart pointer will deal with the Destructor call if necessary
		boost::shared_ptr<XCSIT::XPhotonEntry> ne(new PhotonEntry());

		// Add it to the vector at the end of the of the ArrayList
		photonVec.push_back(ne);

		photonNum++;
		
		// Return the created instance
		return ne;
	}

    size_t PhotonData::size() const {
		return photonNum;
	}

    void PhotonData::clear(){
		photonVec.clear();
		photonVec.resize(0);
		photonNum = 0;
	}

}
