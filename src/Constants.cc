/*
 * Allows to extent the variables to python
 *
 * File:    Constants.cc
 * Author:  jburchert
 * Data:    30 August 2017
 */


#include "Constants.hh"

#include <sstream>
#include <string>



namespace DSIM {

    Constants::Constants(){
        if(DEBUG){
            std::cout << "Constants::Constants" << std::endl;
        }
    }

    Constants::~Constants(){
        if(DEBUG){
            std::cout << "Constants::~Constants" << std::endl;
        }
    }

    int Constants::size(std::string name){
        if(DEBUG){
            std::cout << "Constants::size << " << name <<  std::endl;
        }
        if(name == "DetectorType"){
            return 5;
        }else if(name == "PlasmaSim"){
            return 1;
        }else if(name == "PlasmaSearch"){
            return 1;
        }else if(name == "ChargeProp"){
            return 4;
        }else{
            throw std::invalid_argument("Currently stored are: \"DetectorType\", \"PlasmaSim\", \"PlasmaSearch\", \"ChargeProp\"");
        }
    }

    
    std::string Constants::varValue(std::string name,int element){
        if(DEBUG){
            std::cout << "Constants::varValue << " << name << " << " << element << std::endl;
        }
        if(element < 0 || element >= size(name)){
            std::stringstream stst;
            stst << name << " has only elements between 0 and " << size(name);
            throw std::out_of_range(stst.str());
        }

        if(name == "DetectorType"){
            return DetectorType[element];
        }else if(name == "PlasmaSim"){
            return PlasmaSim[element];
        }else if(name == "PlasmaSearch"){
            return PlasmaSearch[element];
        }else if(name == "ChargeProp"){
            return ChargeProp[element];
        }
        // other cases are already dealt with by calling size(name)
    }
}
