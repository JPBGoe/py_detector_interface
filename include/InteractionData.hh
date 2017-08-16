/*
 * Instances of this class act as containers for interactions. They include instances
 * describing the properties of single interactions. 
 *
 * File:	InteractionData.hh
 * Author:	jburchert
 * Date:	9 August 2017
 */
#ifndef INTERACTIONDATA_HH
#define INTERACTIONDATA_HH

#include "XInteractionData.hh"
#include "XInteractionEntry.hh"
#include "InteractionEntry.hh"
#include <vector>

namespace DSIM {

    class InteractionData : public XCSIT::XInteractionData{

    public:
    	InteractionData();
    	~InteractionData();
	
		boost::shared_ptr<InteractionEntry> getPyEntry(size_t entry);
		boost::shared_ptr<InteractionEntry> addPyEntry();
    	

		// Implementation of the functions declared in XInteractionData.hh	
		boost::shared_ptr<XCSIT::XInteractionEntry> getEntry(size_t entry);
        boost::shared_ptr<XCSIT::XInteractionEntry> addEntry();
        size_t size() const;
        void clear();
        

    private:

		// Variables to store the InteractionEntry instances
   		std::vector<boost::shared_ptr<InteractionEntry> > iaVec;
   		size_t iaNum;
    };
}

#endif
