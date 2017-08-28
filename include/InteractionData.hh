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
    /**
     * Instances of this class implement the XCSIT::XInteractionData class from
     * the xcsit software. They store instances of the InteractionEntry classes
     */
    class InteractionData : public XCSIT::XInteractionData{

    public:
        /**
         * Constructor
         */
    	InteractionData();
        /**
         * Desturctor
         */
    	virtual ~InteractionData();

		// Implementation of the functions declared in XInteractionData.hh
        /**
         * @param entry position of the returned instance in this container
         * @return the XCSIT:XInteractionEntry saved at the position entry
         */
		virtual boost::shared_ptr<XCSIT::XInteractionEntry> getEntry(size_t entry);
        /**
         * @return the XCSIT::XInteractionEntry instance which is added to 
         * the container by calling this function
         */
        virtual boost::shared_ptr<XCSIT::XInteractionEntry> addEntry();
        /**
         * @return the number of elements currently stored in this container
         */
        virtual size_t size() const;
        /**
         * clears this container by deleting all its content
         */
        virtual void clear();
        

    private:

		// Variables to store the InteractionEntry instances
   		std::vector<boost::shared_ptr<XCSIT::XInteractionEntry> > iaVec;
   		size_t iaNum;
    };
}

#endif
