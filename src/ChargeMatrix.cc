/*
 * File:	ChargeMatrix.cc
 * Author:	jburchert
 * Date:	15 August 2017
 */
#include "ChargeMatrix.hh"
#include <stdexcept>


namespace DSIM {

	ChargeMatrix::ChargeMatrix(){	
		xSize = 0;
		ySize = 0;

		// init with 1 x 1 content
		setSize(1,1);
	}

	ChargeMatrix::~ChargeMatrix(){ // has to delete the matrix
		clear();
	}			

	// this functions include an clear() on the instance calling
	void ChargeMatrix::setSize(size_t x, size_t y){
		// Check the input
		if(x <= 0 || y <= 0){
			throw std::invalid_argument("Matrix dimensions have to be greater that 0");
		}

		// overall number of elements that need to be created
		size_t num = x*y;

		// fill the Content
		fillContent(num);
		
		// Remembering the size
		xSize = x;
		ySize = y;
	}

	boost::shared_ptr<XCSIT::XChargeEntry> ChargeMatrix::getEntry(size_t x, size_t y){
		return getPyEntry(x,y);
	}

	boost::shared_ptr<ChargeEntry> ChargeMatrix::getPyEntry(size_t x, size_t y){
		// check if there is something to return
		if(xSize <= 0 || ySize <= 0){
			throw std::invalid_argument("No Data in the matrix to return");
		}
		if(x >= xSize || y >= ySize){
			throw std::out_of_range("Index is bigger than matrix dimension");
		}

		// calculate back to the coodinates of the array
		// Structure: x1y1 x1y2 x1y3 ... x1yy x2y1 x2y2 x2y3 x2y4 ... xxyy
		size_t index = x*ySize + y;

		return Content[index];
	}

	size_t ChargeMatrix::width() const{
		return xSize;
	}

	size_t ChargeMatrix::height() const{
		return ySize;
	}

	void ChargeMatrix::clear(){
		Content.clear();
		Content.resize(0);
		xSize = 0;
		ySize = 0;
	}

	void ChargeMatrix::fillContent(size_t num){
		if(xSize != 0 || ySize != 0){
			throw std::invalid_argument("Please clear() the ChargeMatrix before setting it to a new size");
		}

		// Create the elements and save them in the 
		for(int i = 0; i < num; i++){
			boost::shared_ptr<ChargeEntry> nce(new ChargeEntry);
			Content.push_back(nce);
		}
	}

	
}

