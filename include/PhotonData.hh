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
#include <iostream>
#define DEBUG 1


namespace DSIM {
    /**
     * Instance of this class acts like a container class that store
     * entries containing data about the photons
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
    	virtual ~PhotonData();
	

		// Implementation of the functions declared in XPhotonData.hh	
	    /** 
         * @param entry number of the XCSIT::XPhotonEntry
         * @retrun a shared_pointer to the XPhotonEntry stored at entry
         */	
        virtual boost::shared_ptr<XCSIT::XPhotonEntry> getEntry(size_t entry);
        /**
         * Create a new element in the container
         * @return the created element
         */
        virtual boost::shared_ptr<XCSIT::XPhotonEntry> addEntry();
        /**
         * @return the number of entries currently stored in this instance
         */
        virtual size_t size() const;
        /**
         * deletes all the entires currently stored in this instance. Calling
         * size() must return 0 and there souldn't be any instances returned
         * with getter function
         */
        virtual void clear();
    
    private:

		// Variables to store the PhotonEntry instances
   		std::vector<boost::shared_ptr<XCSIT::XPhotonEntry> > photonVec;
   		size_t photonNum;
    };
}

#endif
