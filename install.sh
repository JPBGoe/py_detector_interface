#!/bin/bash

rm -r ./build
mkdir ./build
cd ./build

#TODO: The user is asked to edit the two options
cmake \
	-DXCSIT_FOLDER=/gpfs/exfel/data/user/burcherj/Development/karaboFramework/karabo/devices/xcsit \
	-DGEANT4_FOLDER=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01 \
  	-DXERCES=/gpfs/exfel/data/user/burcherj/Development/xerces-c-3.1.4/src \
  	-DCIMG=/gpfs/exfel/data/user/burcherj/Development/karaboFramework/karabo/extern \
	..
make
make install
