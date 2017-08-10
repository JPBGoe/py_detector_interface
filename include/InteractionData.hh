/*
 * Instances of this class act as containers for interactions. They include instances
 * describing the properties of single interactions. 
 *
 * File:	InteractionData.hh
 * Author:	jburchert
 *
 * Created on 9 August 2017
 */
#ifndef INTERACTIONDATA_HH
#define INTERACTIONDATA_HH

#include "XInteractionData.hh"
#include "XInteractionEntry.hh"
#include <vector>

namespace DSIM {

    class InteractionData : public XCSIT::XInteractionData{

    public:
    	InteractionData();
    	~InteractionData();
    
		// Implementation of the functions declared in XInteractionData.hh	
		boost::shared_ptr<XCSIT::XInteractionEntry> getEntry(size_t entry);
        boost::shared_ptr<XCSIT::XInteractionEntry> addEntry();
        size_t size() const;
        void clear();
        

    private:
		// Variables to store the InteractionEntry instances
   		std::vector<boost::shared_ptr<XCSIT::XInteractionEntry>> iaVec;
   		size_t iaNum;
    };
}

#endif
