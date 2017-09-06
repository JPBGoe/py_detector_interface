/*
 * File:   	PhotonData.cc
 * Author: 	jburchert
 * Date:	10 August 2017
 */

#include "PhotonData.hh"
#include <stdexcept>

namespace DSIM {

    PhotonData::PhotonData(){
        if(DEBUG){
            std::cout << "PhotonData::PhotonData()" << std::endl;
		}
        // initialization
		clear();
    }

    PhotonData::~PhotonData(){
        if(DEBUG){
            std::cout << "PhotonData::~PhotonData()" << std::endl;
        }
    }

	boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::getEntry(size_t entry){
        if(DEBUG){
            std::cout << "PhotonData::getEntry << " << entry << std::endl;
		}
        if(entry < 0 || entry >= photonNum){
			throw std::invalid_argument("value does not fit to number of elements in this instance");
		}

		return photonVec[entry];
	}

    boost::shared_ptr<XCSIT::XPhotonEntry> PhotonData::addEntry(){
        if(DEBUG){
            std::cout << "PhotonData::addEntry" << std::endl;
		}
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
        if(DEBUG){
            std::cout << "PhotonData::size >> " << photonNum << std::endl;
		}
        return photonNum;
	}

    void PhotonData::clear(){
        if(DEBUG){
            std::cout << "PhotonData::clear" << std::endl;
		}
        photonVec.clear();
		photonVec.resize(0);
		photonNum = 0;
	}

}
