# py_detector_interface

## Aim of this program

The detection of photons from a beam is normally performed by an ccd detector. The signal, a number of registered photons, is determined by the interaction of the photons with the material of the detector. Unfortunatelly, the geometry of the detector and the registration method itself has an influence on the measured signal itself. In an real experiment this has to be taken into account but the simulations can help to understand occuring phenonema and by this can also improve the outcome of an experiment. 

Today there are already solutions to the problem of simulating a detector. The CERN geant4 (data base) and xcsit which make its accessable is a frequently used combination to simulate many kinds of interactions. Those calculated events can easyly be translated into an electron matrix, the signal,  by using xdsp which also takes the detector design into account. Unfortunatelly, those programs are written in C++ and are still unaccessable from python. The aim of this purpose is to change this.

SimEx is simulation framework, which can be used to sumulate an experiment at an free electron laser. It utilizes classes and data structures to shape the pattern of an experiment from its source via arbitrary optical elements containing a sample to an detector.  It is written in python. This project shall improve the detector by including the features provided by geant4, xscit and xdsp.

## Requirements

- Installation:	geant4
- Installation: xscit
- Installation: boost libraries
- Installation: python libraries
- Installation: xerces-c libraries
- Unix OS

## Installation

To install this software, other software has to be installed first. If this software is already installed on your computer, you can skip the part installing that software. The excamples below show how to build the software if you are not having root rights.

### XercesC 

Please install the latest version of XercesC, which can be downloaded from http://xerces.apache.org/xerces-c/download.cgi

1) download and unzip the latest version of xerces-c-VER.tar.gz in the directory where you want to build the software:

	$> tar -xvzf xerces-c-<ver>.tar.gz
	
2) configure with the path to your local directory

	$> ./configure --prefix=/home/USERNAME/.local
	
3) compile and link

	$> make
	
4) copy compiled files to prefix location

	$> make install

### Geant4

### xcsit

### py_detector_interface


Please use the "install.sh" and "env.sh.in" to install this program to your
system. Currently Unix is the only supported operation system. 

1) open install.sh and edit the variables. Therefore, you need to enter the
    absolut pathes to your geant4 and xcsit folders

2) open additionally env.sh.in Check if the exported pathes are existant on your
	computer utilizing the pathes used in 1) to replace the variables. If the
	versions differ, please edit them in env.sh.in

3) close install.sh and env.sh.in 

4) make install.sh executable
	
	$> chmod u+x install.sh

5) execute the installation. There should not be any warnings or errors
	
	$> ./install.sh

## Previous to usage

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

## Acknowledgements

This project has received funding from the European Union’s Horizon 2020 research and innovation programme under grant agreement No 654220.
