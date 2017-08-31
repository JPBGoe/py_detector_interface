/*
 * Remarks: x, y start with 0 as their first index
 *
 * File:	ChargeMatrix.hh
 * Author:	jburchert
 * Date:	15 August 2017
 */
#ifndef CHARGEMATRIX_HH
#define CHARGEMATRIX_HH

#include <boost/shared_ptr.hpp>
#include "XChargeData.hh"
#include "XChargeEntry.hh"
#include "ChargeEntry.hh"
#include <vector>
#include <iostream>

#define DEBUG 1

namespace DSIM {
    /**
     * Instances of this class store DSIM::ChargeEntry instances in a matrix 
     * reflecting the detector pixels
     */
	class ChargeMatrix : public XCSIT::XChargeData{
	
		public:
            /**
             * Constructor
             */
			ChargeMatrix();	// init with 1 x 1
            ChargeMatrix(size_t x, size_t y);
            /**
             * Destructor
             */
			virtual ~ChargeMatrix(); // has to delete the matrix
			
			// this functions include an clear() on the instance calling
			/**
             * To use this function, the clear() function has to be called
             * first. It sets the size of a new ChargeMatrix.
             * @param x the new size of the matrix in x direction
             * @param y the new size of the matrix in y direction
             */
			virtual void setSize(size_t x, size_t y);
            /**
             * @return the XCSIT::XChargeEntry by calling getPyEntry at the
             * given position in the matrix
             * @param x x position of the requested entry
             * @param y y position of the requested entry
             */
			virtual boost::shared_ptr<XCSIT::XChargeEntry> getEntry(size_t x, size_t y);
            /**
             * @return the size of the storage matrix in x direction
             */
			virtual size_t width() const;
            /**
             * @return the size of the storage matrix in y direction
             */
			virtual size_t height() const;

			// Deletes all the entries of the matrix has to be initialized again
			// with setSize
			/**
             * clears the ChargeMatrix. To be able to call other functions
             * setSize(...,...) has to be called previously
             */
			virtual void clear();

		private:
			void fillContent(size_t);
			size_t xSize;	// width
			size_t ySize;	// height
			std::vector<boost::shared_ptr<XCSIT::XChargeEntry> > Content;

	};
}

#endif
