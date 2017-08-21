#!/bin/sh
#
#	Raw form of the file setting the environment variables that are necessary to
#	run a simulation including geant4, xcsit and py_detector_simulation
#
#	File:	env.sh.in
#	Author: jburchert
#	Date:	21 August 2017
#

# Variable is required to make python find the shared objects containing the the
# exported c++ classes
export PYTHONPATH=/gpfs/exfel/data/user/burcherj/Development/py_detector_interface/build/src:$PYTHONPATH
echo "Adding /gpfs/exfel/data/user/burcherj/Development/py_detector_interface/build/lib to the PYTHONPATH" 

# variable necessary for the particle simulation. Somewhere deep in geant4 this
# variable is used
# the number needs to be changed if necessary
export G4ENSDFSTATEDATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/G4ENSDFSTATE2.1
echo "Setting G4ENSDFSTATEDATA"

# the following lines are copied and adjusted from setG5EnvironmentalVariables.sh
export G4ABLADATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/G4ABLA3.0
echo "Setting G4ABLADATA"

export G4LEDATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/G4EMLOW6.50
echo "Setting G4LEDATA"

export G4NEUTRONHPDATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/G4NDL4.5
echo "Setting G4NEUTRONHPDATA"

export G4NEUTRONXSDATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/G4NEUTRONNXS1.4
echo "Setting G4NEUTRONXSDATA"

export G4PIIDATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/G4PII1.4
echo "Setting G4PIIDATA"

export G4SAIDXSDATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/G4SAIDDATA1.1
echo "Setting G4SAIDXSDATA"

export G4LEVELGAMMADATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/PhotonEvaporation4.3.2
echo "Setting G4LEVELGAMMADATA"

export G4RADIOACTIVEDATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/RadioactiveDecay5.1.1
echo "Setting G4RADIOACTIVEDATA"

export G4REALSURFACEDATA=/gpfs/exfel/data/user/burcherj/Development/geant4.10.03.p01-build/data/RealSurface1.0
echo "Setting G4REALSURFACEDATA"


# Report finished
echo "Done"
