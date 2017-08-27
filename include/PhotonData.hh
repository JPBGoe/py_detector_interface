/*
 * Instances of this class act as containers for photons. They include instances
 * describing the properties of single photons. 
 *
 * File:	PhotonData.hh
 * Author:	jburchert
 * Date:	9 August 2017
 */
#ifndef PHOTONDATA_HH
#define PHOTONDATA_HH

#include "XPhotonData.hh"
#include "XPhotonEntry.hh"
#include "PhotonEntry.hh"
#include <vector>

namespace DSIM {
    /**
     * Class that implements XCSIT::XPhotonData from the xcsit software
     * It acts like a container class that stores DSIM::PhotonEntry instances
     */
    class PhotonData : public XCSIT::XPhotonData{

    public:
        /**
         * Constructor: Initialize the attributes
         */
    	PhotonData();
        /**
         * Destructor
         */
    	~PhotonData();
	
        /** 
         * @param entry number of the DSIM::PhotonEntry
         * @retrun a shared_pointer to the PhotonEntry stored at entry
         */
		boost::shared_ptr<PhotonEntry> getPyEntry(size_t entry);
        /**
         * Creates a new DSIM::PhotonEntry
         * @return the newly created instance of a DSIM:PhotonEntry
         */
        boost::shared_ptr<PhotonEntry> addPyEntry();
    	

		// Implementation of the functions declared in XPhotonData.hh	
	    /** 
         * Internally boost::shared_ptr<PhotonEntry> getPyEntry is used
         * @param entry number of the XCSIT::XPhotonEntry
         * @retrun a shared_pointer to the XPhotonEntry stored at entry
         */	
        boost::shared_ptr<XCSIT::XPhotonEntry> getEntry(size_t entry);
        boost::shared_ptr<XCSIT::XPhotonEntry> addEntry();
        /**
         * @return the number of entries currently stored in this instance
         */
        size_t size() const;
        /**
         * deletes all the entires currently stored in this instance. Calling
         * size() must return 0 and there souldn't be any instances returned
         * with getter function
         */
        void clear();
    
    private:

		// Variables to store the PhotonEntry instances
   		std::vector<boost::shared_ptr<PhotonEntry> > photonVec;
   		size_t photonNum;
    };
}

#endif
