/*
 * File:   	PhotonData.cc
 * Author: 	jburchert
 * Date:	10 August 2017
 */

#include "PhotonData.hh"
#include <stdexcept>
#include <iostream>

namespace DSIM {

    PhotonData::PhotonData(){
        std::cout << "PhotonData::PhotonData()" << std::endl;
		// initialization
		clear();
    }

    PhotonData::~PhotonData(){
        std::cout << "PhotonData::~PhotonData()" << std::endl;
    }

	
	/*boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::getEntry(size_t entry){
		return getPyEntry(entry);
	}

    boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::addEntry(){
		return addPyEntry();
	}*/

	boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::getEntry(size_t entry){
        std::cout << "PhotonData::getEntry <<" << entry << std::endl;
		if(entry < 0 || entry >= photonNum){
			throw std::invalid_argument("value does not fit to number of elements in this instance");
		}

		return photonVec[entry];
	}

    boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::addEntry(){
        std::cout << "PhotonData::addEntry" << std::endl;
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
        std::cout << "PhotonData::size >>" << photonNum << std::endl;
		return photonNum;
	}

    void PhotonData::clear(){
        std::cout << "PhotonData::clear" << std::endl;
		photonVec.clear();
		photonVec.resize(0);
		photonNum = 0;
	}

}
