/*
 * Store the options that can be used in simulations
 * Inheritance to allow also the use in private functions
 *
 * File:   	Constants.hh
 * Author: 	jburchert
 * Date:	29 August 2017
 *
 */

#ifndef CONSTANTS_HH
#define	CONSTANTS_HH

#include <string>
#include <stdexcept>
#include <iostream>

// Also affects ParticleSim and ChargeSim
#ifdef DEBUGMODE
    #define DEBUG 1
#else
    #define DEBUG 0
#endif

namespace DSIM {
    /**
     * This class does only include shared constants
     */
    class Constants{
    
        public:
            /**
             * Constructor
             */
            Constants();
            
            /**
             * Destructor
             */
            virtual ~Constants();


            /**
             * @param name name of the variable
             * @return the number of element stored in the variable name
             * @throws std::invalid_argument exception if the name is unknown
             */
            virtual int size(std::string name);

            /**
             * @param name name of the variable
             * @param element element of the field of the variable to be
             * returned
             * @return the string stored at (name,element)
             * @throws std::out_of_range exception
             * @throws std::invalid_argument exception if the name is unknown
             */
            virtual std::string varValue(std::string name, int element);

            // the options that need to be implemented at least as well as an
            // exception if the input string is not in one of them
            const std::string DetectorType[5] = {"pnCCD","LPD","AGIPD","AGIPDSPB","CAD"};
            const std::string PlasmaSim[1] = {"BLANKPLASMA"};
            const std::string PlasmaSearch[1] = {"BLANK"};
            const std::string ChargeProp[4] = {"FULL","FANO","LUT","BINNING"};  // LUT has problems
    };
}

#endif
