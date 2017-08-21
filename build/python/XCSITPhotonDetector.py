# IO class imports
import PhotonEntry_ext
import PhotonData_ext
import InteractionEntry_ext
import InteractionData_ext
import ChargeEntry_ext
import ChargeMatrix_ext

# Simulation imports
import ParticleSim_ext
import ChargeSim_ext

import os
import numpy as np

class XCSITPhotonDetector(AbstractPhotonDetector):
	"""
	Class representing an free electorn laser photon detector
	"""
	
	# Define the allowed attributes
	__slot__ = "__parameters", "__expected_data", "__provided_data", 
	"__input_path", "__output_path", "__photon_data", "__ia_data", 
	"__charge_data"


	# Definition of the init
	__init__(self,parameters=None,input_path=None,output_path=None):
		"""
		:param parameters: Parameters of the calulator such as the type of
			detector
		:type parameters: XCSITPhotonDetector

		:param input_path: Path to the hdf5 file holding the input data.
		:type input_path: str

		:param output_path: Path pointing to the path for output
		:type output_path: str
		"""

		# deal with the parameters: Which kind of input? -> Change to Container
		# if necessary
		if isinstance(parameters, dict):
			raise ValueError("Only XCSITPhotonDetectorParameters instances "+
				" are allowed as input")
		if parameters == None:
			raise ValueError("parameters required for simulation")
	
		# Checking of in and output path are given and assign them for storage
		# to internals
		if input_path == None)
			raise ValueError("input_path including the .h5 file has to be specified")
		
		if output_path == None)
			raise ValueError("output_path including the resulting .h5 file has to be specified")

		# input and output path can either be dirctionaries or files but must be
		# relative pathes
		# Cases:
		# 1) ends with .h5     -> it is a file: no action
		# 2) ends without .h5
		# 		a) Such a dictionary exists  -> invent a new file to put in or
		# 		look up existing
		#		b) Such a dictionary does not exist -> filename without .h5
		#		specified, but parent folder has to exist
	
		# Join the current working directory with the relative path given	
		abs_inpath = os.path.normpath(os.path.join(os.getcwd(), input_path))
		if abs_inpath.endswith(".h5"):
			# a specified file
			if not os.path.exists(abs_inpath):
				raise ValueError("File " + str(abs_inpath) + " does not exists")
		else:
			# Check for existing input file
			if os.path.isdir(abs_inpath):
				count = 1
				found = ""
				for file in os.listdir(abs_inpath)
					# the candidates file
					if file.endswith(".h5"):
						found = file
						count -= 1

					# there should be only one candidate file
					if count < 0:
						raise RuntimeError("Multiple files ending with .h5 in "+
							str(abs_inpath))

				if count == 1:
					raise RuntimeError("There is no such input file")
				abs_inpath = os.path.join(abs_inpath, found)

			# last argument is file name	
			else:
				# Check if parent is not an existing directory
				path, test = os.path.split(abs_inpath)
				if not os.path.isdir(path):
					raise RuntimeError("Please specify the input file and path
						directly")
				else:
					abs_inpath += ".h5"

		# Join the current working directory with the relative path given	
		abs_outpath = os.path.normpath(os.path.join(os.getcwd(), output_path))
		if abs_outpath.endswith(".h5"):
			# a specified file
			if not os.path.exists(abs_outpath):
				raise ValueError("File " + str(abs_outpath) + " does not exists")
		else:
			# Check for existing directory
			if os.path.isdir(abs_outpath):
				abs_outpath = os.path.join(abs_out_path,"XCSITDetectorOutput.h5")

			# last argument is file name	
			else:
				# Check if parent is not an existing directory
				path, test = os.path.split(abs_outpath)
				if not os.path.isdir(path):
					raise RuntimeError("Please specify the input file and path
						directly")
				else:
					abs_outpath += ".h5"


		# Save the input in attributes
		self.__parameters = parameters
		self.__input_path = abs_inpath
		self.__output_path= abs_outpath

		# Init base class
		super(XCSITPhotonDetector,self).__init__(parameters,input_path,output_path)

		# Define the input and output structure of the hdf5 file
		self.__expected_data = ['/data/data',
                                '/data/diffr',
                                '/data/angle',
                                '/history/parent/detail',
                                '/history/parent/parent',
                                '/info/package_version',
                                '/info/contact',
                                '/info/data_description',
                                '/info/method_description',
                                '/params/geom/detectorDist',
                                '/params/geom/pixelWidth',
                                '/params/geom/pixelHeight',
                                '/params/geom/mask',
                                '/params/beam/photonEnergy',
                                '/params/beam/photons',
                                '/params/beam/focusArea',
                                '/params/info',
                                ]

		self.__provided_data = ['/data/data',
								'/data/photons'
								'/data/interactions',
								'/data/charge',
                                '/data/diffr',
                                '/data/angle',
                                '/history/parent/detail',
                                '/history/parent/parent',
                                '/info/package_version',
                                '/info/contact',
                                '/info/data_description',
                                '/info/method_description',
                                '/params/geom/detectorDist',
                                '/params/geom/pixelWidth',
                                '/params/geom/pixelHeight',
                                '/params/geom/mask',
                                '/params/beam/photonEnergy',
                                '/params/beam/photons',
                                '/params/beam/focusArea',
                                '/params/info',
                                ]





	def expectedData(self):
		return self.__expectedData

	def providedData(self):
		return self.__providedData

	def getChargeData(self):
		return self.__charge_data

	def getInteractionData(self):
		return self.__ia_data

	def getPhotonData(self):
		return self.__photon_data

	def __createXCSITInteractions(self):
		self.__ia_data = InteractionData_ext.InteractionData()

	def __createXCSITChargeMatrix(self):
		self.__charge_data = ChargeMatrix_ext.ChargeMatrix()
		# Size will be addapted by ParticleSim.cc implementation


	# Subengine to calulate the particle simulation: The interaction of the
	# photons with the detector of choice
	def __backenginIA(self):
		"""
		Run the particle simulation
		"""
		# Check containers
		if self.__photon_data == None:
			raise RuntimeError("photon container has not been initialized yet")
		if self.__ia_data == None:
			raise RuntimeError("interaction container has not been initialized
yet")
		
		# Run the simulation
		ps = ParticleSim_ext.ParticleSim()
		ps.initialization(self.__parameters["detectortype"])
		ps.runSimulation(self.__photon_data,self.__ia_data)
		# Results are directly written to the __ia_data instance
		

	def __backengineCP(self):
		"""
		Run the charge simulation
		"""
		# Check containers
		if self.__ia_data == None:
			raise RuntimeError("interaction container has not been initialized
yet")
		if self.__charge_data == None:
			raise RuntimeError("charge matrix has not been initialized yet")

	
		# Run the simulation
		cs = ChargeSim_ext.ChargeSim()
		cs.setInput(self.__ia_data)
		cs.setComponents(self.__charge_data,
						self.__parameters["plasmasearch"],
						self.__parameters["plasmasim"],
						self.__parameters["pointsim"],
						self.__parameters["detectortype"]
						)
		cs.runSimulation()
		

	def backengine(self):
		"""
		Executes the simulation of the particle and charge simulation
		"""
		print("Simulating photon-detector interaction")
		# Create the containers
		self.__ia_data 		= self.__createXCSITInteractions(self)
		self.__charge_data	= self.__createXCSITChargeMatrix(self)

		# run the particle simulation
		self.__backengineIA(self)
		print("Interaction simulation of the detector is finished")

		# run the charge simulation
		self.__backengineCP(self)		
		print("Charge propagation simulation in the detector is finished")


	def _readH5(self):
		"""
		Reads the hdf5 file and create the storage container for the photons
		according to that data
		"""
		# The __input_path is a non relative path to an existing file
		if not os.path.exists(self.__input_path):
			raise RuntimeError("Input file " + str(self.__input_path) + " does
				not exists")

		# Open the input file
		infile = self.__input_path
		h5_infile 	= h5py.File(infile,"r")

		# Get the necessary data from the directory to specify impuls, position
		# and energy
		# TODO which kind is saved in the input file
		photons = h5_infile["data/data"]

		# Create the photon instance
		self.__photon_data = PhotonData_ext.PhotonData()
		for ph in photons:
			entry = self.__photon_data.addEntry()
			entry.setPositionX(...)
			entry.setPositionY(...)
			entry.setPositionZ(...)
			entry.setDirectionX(...)
			entry.setDirectionY(...)
			entry.setDirectionZ(...)
			entry.setEnergy(...)

		# Close the input file
		h5_infile.close()
		
	def saveH5(self):
		"""
		Save the results in a file
		"""
#        path_to_files = self.__output_path

        # Setup new file.
 #       h5_outfile = h5py.File( self.__output_path, "w")

        # Files to read from
  ##      individual_files = [os.path.join( path_to_files, f ) for f in os.listdir( path_to_files ) ]
    #    individual_files.sort()

        # Keep track of global parameters being linked.
     #   global_parameters = False
        # Loop over all individual files and link in the top level groups.
      #  for ind_file in individual_files:
       #     # Open file.
        #    h5_infile = h5py.File( ind_file, 'r')

            # Links must be relative.
         #   relative_link_target = os.path.relpath(path=ind_file, start=os.path.dirname(os.path.dirname(ind_file)))
            # Link global parameters.
          #  if not global_parameters:
                global_parameters = True

           #     h5_outfile["params"] = h5py.ExternalLink(relative_link_target,
		# "params")
            #    h5_outfile["info"] = h5py.ExternalLink(relative_link_target,
		# "info")
             #   h5_outfile["misc"] = h5py.ExternalLink(relative_link_target,
		# "misc")
              #  h5_outfile["version"] = h5py.ExternalLink(relative_link_target,
		#"version")

#            for key in h5_infile['data']:
#
 #               # Link in the data.
  #              ds_path = "data/%s" % (key)
   #             h5_outfile[ds_path] = h5py.ExternalLink(relative_link_target,ds_path)
#
 #           # Close input file.
  #          h5_infile.close()


	# Write the new data to the h5py output file
		# Convert the photon data to a 2D numpy array   (size x 7)
		num_photon = np.zeros((self.__photon_data.size(),7),dtype=np.float_)
		for i in list(range(self.__photon_data.size())):
			entry = self.__photon_data.getEntry(i)
			num_photon[i,0] = entry.getPositionX()
			num_photon[i,1] = entry.getPositionY()
			num_photon[i,2] = entry.getPositionZ()
			num_photon[i,3] = entry.getDirectionX()
			num_photon[i,4] = entry.getDirectionY()
			num_photon[i,5] = entry.getDirectionZ()
			num_photon[i,6] = entry.getEnergy()


		# Convert the interaction data to a 2D numpy array  (size x 5)
		num_ia = np.zeros((self.__ia_data.size(),5),dtype=np.float_)
			entry = self.__ia_data.getEntry(i)
			num_ia[i,0] = entry.getPositionX()
			num_ia[i,1] = entry.getPositionY()
			num_ia[i,2] = entry.getPositionZ()
			num_ia[i,3] = entry.getEnergy()
			num_ia[i,4] = entry.getTime()


		# Convert the ChargeMatrix to a numpy array to be able to store its
		# content
		x_size = self.__charge_data.width()
		y_size = self.__charge_data.height()
		charge_array = np.zeros((x_size,y_size),dtype=np.float_)	# float64
		for x in list(range(x_size)):
			for y in list(range(y_size)):
				entry = self.__charge_data.getEntry(x,y)
				charge_array[x,y] = entry.getCharge()
				

		# Create the output file
		h5_outfile = h5py.File( self.__output_path, "w")

		# Create the groups of the output file
		datagr = h5_outfile.create_group("data")
		histgr = h5_outfile.create_group("history")
		infogr = h5_outfile.create_group("info")
		miscgr = h5_outfile.create_group("misc")
		paramsgr = h5_outfile.create_group("params")
		versiongr = h5_outfile.create_group("version")
		
		# Link the elements of the input file
		h5_outfile["history"] = h5py.ExternalLink(self.__input_file, "history")
		h5_outfile["info"] = h5py.ExternalLink(self.__input_file, "info")
		h5_outfile["params"] = h5py.ExternalLink(self.__input_file, "params")
		h5_outfile["version"] = h5py.ExternalLink(self.__input_file, "version")	

		# for every key in data group create an External link

		# Add the own data as datasets to the file
		photonset = datagr.create_dataset("photons",data=num_photon)
		photonset.attrs["0"] = "x position";
		photonset.attrs["1"] = "y position";
		photonset.attrs["2"] = "z position";
		photonset.attrs["3"] = "x direction";
		photonset.attrs["4"] = "y direction";
		photonset.attrs["5"] = "x direction";
		photonset.attrs["6"] = "energy";

		iaset = datagr.create_dataset("interactions",data=num_ia)
		iaset.attrs["0"] = "x position";
		iaset.attrs["1"] = "y position";
		iaset.attrs["2"] = "z position";
		iaset.attrs["3"] = "energy";
		iaset.attrs["4"] = "time";

		chargeset = datagr.create_dataset("chargematrix",data=charge_array)
		chargeset.attrs["elems"] = "charge at that position";



        # Close file.
        h5_outfile.close()

        # Reset output path.
        self.output_path = self.output_path+".h5"



