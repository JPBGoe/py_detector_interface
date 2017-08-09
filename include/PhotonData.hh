/*
 * Instances of this class act as containers for photons. They include instances
 * describing the properties of single photons. 
 *
 * File:	PhotonData.hh
 * Author:	jburchert
 *
 * Created on 9 August 2017
 */
#ifndef PHOTONDATA_HH
#define PHOTONDATA_HH

#include "XPhotonData.hh"
#include "PhotonEntry.hh"
#include <vector>

namespace DSIM {

    class PhotonData : public XCSIT::XPhotonData{

    public:
    	PhotonData();
    	~PhotonData();
    
		// Implementation of the functions declared in XPhotonData.hh	
		boost::shared_ptr<XPhotonEntry> getEntry(size_t entry);
        boost::shared_ptr<XPhotonEntry> addEntry();
        size_t size();
        void clear();
        

    private:
		// Variables to store the PhotonEntry instances
   		std::vector<boost::shared_ptr<PhotonEntry>> photonVec;
   		size_t photonNum;
    };
}

#endif
