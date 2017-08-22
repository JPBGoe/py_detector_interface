#!/bin/bash

# Create a new folder for the build 
rm -r ./build
mkdir ./build
cd ./build

# TODO:
# Please edit the pathes below according to your file system
# If your have another version of xerces_c than 3.1 please edit also the single
# entry in ./src/CMakeLists.txt which starts with ${XERCES} and ends with .so
cmake \
	-DXCSIT_FOLDER=/gpfs/exfel/data/user/burcherj/Development/karaboFramework/karabo/devices/xcsit \
	-DGEANT4_SOURCE=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01/source \
	-DGEANT4_BUILD=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build \
	-DGEANT4_SO=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-install/lib64 \
  	-DXERCES=/gpfs/exfel/data/user/burcherj/Development/xerces-c-3.1.4/src \
	..

# Compile the c++ classes
make 

# Copy files to different locations
make install
