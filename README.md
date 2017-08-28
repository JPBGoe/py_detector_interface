# py_detector_interface

## Aim of this program

The detection of photons from a beam is normally performed by an ccd detector. The signal, a number of registered photons, is determined by the interaction of the photons with the material of the detector. Unfortunatelly, the geometry of the detector and the registration method itself has an influence on the measured signal itself. In an real experiment this has to be taken into account but the simulations can help to understand occuring phenonema and by this can also improve the outcome of an experiment. 

Today there are already solutions to the problem of simulating a detector. The CERN geant4 (data base) and xcsit which make its accessable is a frequently used combination to simulate many kinds of interactions. Those calculated events can easyly be translated into an electron matrix, the signal,  by using xdsp which also takes the detector design into account. Unfortunatelly, those programs are written in C++ and are still unaccessable from python. The aim of this purpose is to change this.

SimEx is simulation framework, which can be used to sumulate an experiment at an free electron laser. It utilizes classes and data structures to shape the pattern of an experiment from its source via arbitrary optical elements containing a sample to an detector.  It is written in python. This project shall improve the detector by including the features provided by geant4, xscit and xdsp.

## Requirements

- Unix OS
- cmake
- Installation: xerces-c libraries
- Installation:	geant4
- Installation: boost libraries
- Installation: xscit
- Installation: python libraries

## Installation

To install this software, other software has to be installed first. If this software is already installed on your computer, you can skip the part. The examples below show how to build the software without root privileges. In this case all the required software is installed into a hided folder "./local" of the home directory of the user. In case one has root priviliges "--prefix" as well as "-DCMAKE_INSTALL_PREFIX" options can be left out. In this case the default installation directory "/usr/local" is used instead of "/home/USERNAME/.local". This has to be changed in the remaining options. 

### XercesC 

Please install the latest version of XercesC, which can be downloaded e.g. from http://xerces.apache.org/xerces-c/download.cgi

1) download and extract the latest version of xerces-c-VER.tar.gz in the directory where you want to build the software:

	$> tar -xvzf xerces-c-<ver>.tar.gz
	
2) configure with the path to your local directory:

	$> ./configure --prefix=/home/USERNAME/.local
	
3) compile and link:

	$> make
	
4) copy compiled files to prefix location:

	$> make install

### Geant4

Please use the installation guide from http://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/InstallationGuide/html/
It specifies how geant4 can be installed.

1) Download and extract the latest version of Geant4 e.g. from https://geant4.web.cern.ch/geant4/support/download.shtml :

	$> tar -xvzf geant4.VER.SION.tar.gz

2) create a folder at the same level as your extracted folder:

	$> mkdir geant4-build
	
	$> ls
	
		geant4.VER.SION       geant4-build

	$> cd geant4-build

3) in your geant4 build folder execute cmake to create the Makefile.

	$> cmake -DGEANT4_INSTALL_DATA=ON -DCMAKE_INSTALL_PREFIX=/home/USERNAME/.local -DXERCES_ROOT_DIR=PATH TO THE XERCESC ROOT DIRECTORY ../geant4.VER.SION
	 

4) compile and link libraries

	$> make -jN VERBOSE=1
	
5) copy created files to the CMAKE_INSTALL_PREFIX

	$> make install
	
Annotation:

- Sometimes "GEANT4_INSTALL_DATA=ON" fails to download the data packages for geant4 at the first time. In this case there 		are no files or folders in CMAKE_INSTALL_PREFIX/share/Geant4*/*. This can be solved by either running the process 		again from step 3 or installing those files manually. A guide for that you can find on the geant4 website.
- "PATH TO THE XERCESC ROOT DIRECTORY" should be the directory that contains the folders "include" and "lib" with the 			xercesc files.
- "VERBOSE=1" can be left out if there are no errors during compilation
- "N" specifies the number of kernals of your computer

### xcsit

xsit can be installed with the "xcsit_install.sh" file. It performs the following steps. Please edit the pathes according to your file system.

1) get the xcsit package from gitlab by cloning it:

	$> git clone URL
	
2) Create a build folder inside the cloned directory:

	$> cd xcsit
	
	$> mkdir ./build
	
	$> cd ./build
	
3) Execute cmake to create a Makefile:

	$> cmake -DGEANT4_ROOT=/home/USERNAME/.local -DXERCESC_ROOT=/home/USERNAME/.local -DCMAKE_INSTALL_PREFIX=/home/USERNAME/.local ..

Make sure that the path used for XERCESC_ROOT is the same which was used during configuration of geant4.

4) Compile and link"
	
	$> make VERBOSE=1

5) Copy compiled files to the CMAKE_INSTALL_PREFIX:

	$> make install

Annotation:

- It is necessary that "-DXERCESC_ROOT" describes the same path as "-DXERCES_ROOT_DIR" from geant4 installation

### py_detector_interface

py_detector_interface can be installed with the "xcsit_install.sh" file. It performs the following steps. Please edit the pathes according to your file system.

1) get the xcsit package from gitHub by cloning it:

	$> git clone URL
	
2) create a build folder inside the repository folder and change into it:

	$> mkdir ./build
	
	$> cd ./build

3) create the Makefile:
	
	$> cmake -DGEANT4_ROOT=/home/USERNAME/.local -DXERCESC_ROOT=/home/USERNAME/.local -DXCSIT_ROOT=/home/USERNAME/.local \
-DBOOST_ROOT=/home/USERNAME/.local -DCMAKE_INSTALL_PREFIX=/home/USERNAME/.local ..

4) compile and link:

	$> make
	
5) Copy the created library and header files to the correct location:

	$> make install


## Previous to usage

Previous to each usage of this software environmental variables need to be set. In order to do this either "py_detector_interface_env.sh' needs to be sourced or its content needs to be added to the ".bashrc" file. If one uses another shell than bash, this filename might differ.

### Source in each new terminal window

To source only for the current terminal window, go to the directory where this software is installed. Please type

   $> source py_detector_interface_env.sh

which will set local environmental variables. This needs to be done in every terminal. It requires that "/home/USERNAME/.local/bin" is part of your PATH variable. Otherwise change to the "build" directory of py_detector_interface" and execute the command there.

### Permanently source

To permanently store those environmental variables open "py_detector_interface_env.sh' and copy the commands (export ...) from it. You need to replace "$(version_lookup "NAME*")"  with the actual path to "NAME" in "CMAKE_INSTALL_PATH/share/Geant4*/data":
 
1) Open ".bashrc" with your editor:

   $> cd ~

   $> <editor> ./.bashrc
   
2) Open "./build/py_detector_interface_env.sh" with an editor in another terminal window.

3) Copy the lines from "py_detector_interface_env.sh" starting with "export" to your ".bashrc" and replace "$(version_lookup "NAME*")" with the actual path

## Acknowledgements

This project has received funding from the European Union’s Horizon 2020 research and innovation programme under grant agreement No 654220.
