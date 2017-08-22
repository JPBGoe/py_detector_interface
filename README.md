![](https://www.eucall.eu/sites/sites_custom/site_eucall/content/e21597/e25317/e35463/EUCALLnetworklogos.jpg?preview=preview)

# py_detector_interface

## Aim of this program

The detection of photons from a beam is normally performed by an ccd detector. The signal, a number of registered photons, is determined by the interaction of the photons with the material of the detector. Unfortunatelly, the geometry of the detector and the registration method itself has an influence on the measured signal itself. In an real experiment this has to be taken into account but the simulations can help to understand occuring phenonema and by this can also improve the outcome of an experiment. 

Today there are already solutions to the problem of simulating a detector. The CERN geant4 (data base) and xcsit which make its accessable is a frequently used combination to simulate many kinds of interactions. Those calculated events can easyly be translated into an electron matrix, the signal,  by using xdsp which also takes the detector design into account. Unfortunatelly, those programs are written in C++ and are still unaccessable from python. The aim of this purpose is to change this.

SimEx is simulation framework, which can be used to sumulate an experiment at an free electron laser. It utilizes classes and data structures to shape the pattern of an experiment from its source via arbitrary optical elements containing a sample to an detector.  It is written in python. This project shall improve the detector by including the features provided by geant4, xscit and xdsp.

## Requirements

- Installations of geant4, xscit and xdsp
- Installation of boost.python
- Unix OS

## Installation

Please build this from sources:
 1) change to the folder, where you want to store/ install this program
 2) clone the master branch to this folder

     $> git clone <clone url>
    
 3) create a folder build 

     $> mkdir build
    
  and change to it
  
     $> cd build
    
 4) execute cmake to locate all the necessary libraries

     $> cmake ..
    
 5) compile the files:

     $> make
    
 6) copy the created shared objects to their destination
    
     $> make install

## Preusage

Previous to each usage of this software environmental variables need to be set. In order to do this either 'env.sh' needs to be sourced or its content needs to be added to the '.bashrc' file. Mind that in another shell than bash the filename might differ. In that case please consult the man pages of the shell.

### Source in each new terminal window


To source only for the current terminal window, go to the directory where this software is installed. Please type

   $> source ./env.sh

which will set local environmental variables which are only valid in the scope of the terminal where this is executed.

### Permanently source


To permanently store those environmental variables open 'env.sh' and copy the commands (export ...) from it. Go to your home directory:
  
   $> cd ~

Open './.bashrc' with an editor of your choice:

   $> <editor> ./.bashrc
  
and add the lines from 'env.sh' to it. Save the file and close it. Also close the terminal.
