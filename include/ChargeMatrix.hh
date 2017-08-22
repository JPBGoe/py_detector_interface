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

namespace DSIM {

	class ChargeMatrix : public XCSIT::XChargeData{
	
		public:
			ChargeMatrix();	// init with 1 x 1
			virtual ~ChargeMatrix(); // has to delete the matrix
			
			// this functions include an clear() on the instance calling
			virtual void setSize(size_t x, size_t y);

			virtual boost::shared_ptr<XCSIT::XChargeEntry> getEntry(size_t x, size_t y);
			virtual boost::shared_ptr<ChargeEntry> getPyEntry(size_t x, size_t y);
			virtual size_t width() const;
			virtual size_t height() const;

			// Deletes all the entries of the matrix has to be initialized again
			// with setSize
			virtual void clear();

		private:
			void fillContent(size_t);
			size_t xSize;	// width
			size_t ySize;	// height
			std::vector<boost::shared_ptr<ChargeEntry> > Content;

	};
}

#endif
