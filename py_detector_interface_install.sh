#!/bin/bash

#   Shell script that contains a possible way to install the
#   py_detector_interface software without the need to install the karabo
#   framework
#
#   TODO:
#       change the path to the install roots of various other softwares
#       according to the current installation state of your computer
#
#   File:   py_detector_interface_install.sh
#   Author: jburchert
#   Date:   27 August 2017
#

# Create a new folder for the build 
rm -r ./build
mkdir ./build
cd ./build

# Create a Makefile, here the pathes have to be changed
cmake \
-DGEANT4_ROOT=/home/burcherj/.local \
-DXERCESC_ROOT=/home/burcherj/.local \
-DXCSIT_ROOT=/home/burcherj/.local \
-DBOOST_ROOT=/home/burcherj/.local \
-DCMAKE_INSTALL_PREFIX=/home/burcherj/.local \
-DDEBUG=ON \
..

# Compile and link the c++ classes
make 

# Copy files to the CMAKE_INSTALL_PREFIX location
make install
