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

		:param output_path: Path to hdf5 file for output
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
		if input_path == None:
			raise ValueError("input_path of the hdm5 file has to be specified")
		
		if output_path == None:
			raise ValueError("output_path of the resulting hdm5 file has to be specified")

		# Save the input in attributes
		self.__parameters = parameters
		self.__input_path = input_path
		self.__output_path= output_path

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
								'/data/charge',
								'/data/interactions',
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
		self.__charge_data.setSize(1,1)	# Will be addapted by ParticleSim.cc
		# implementation


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
		# Create a new storage object and assign it to the instance variable
		self.__photon_data = PhotonData_ext.PhotonData()

		# Check if __input_path is dir or file
		if os.path.isdir(self.__input_path):
			input_dir = self.__input_path
		else:
			input_dir = os.path.dirname(self.__input_path)

		
        # Link the  python utility so the backengine can find it.
        ### Yes, this is messy.
        preph5_location = inspect.getsourcefile(prepHDF5)
        if preph5_location is None:
            raise RuntimeError("prepHDF5.py not found. Aborting the calculation.")


		
	def saveH5(self):
		"""
		Save the results in a file
		"""
		
		# Path where individual h5 files are located.
        path_to_files = self.__output_path

        # Setup new file.
        h5_outfile = h5py.File( self.__output_path + ".h5" , "w")

        # Files to read from.
        individual_files = [os.path.join( path_to_files, f ) for f in os.listdir( path_to_files ) ]
        individual_files.sort()

        # Keep track of global parameters being linked.
        global_parameters = False
        # Loop over all individual files and link in the top level groups.
        for ind_file in individual_files:
            # Open file.
            h5_infile = h5py.File( ind_file, 'r')

            # Get file ID.
            file_ID = os.path.split(ind_file)[-1].split(".h5")[0].split("_")[-1]

            # Links must be relative.
            relative_link_target = os.path.relpath(path=ind_file, start=os.path.dirname(os.path.dirname(ind_file)))

            # Link global parameters.
            if not global_parameters:
                global_parameters = True

                h5_outfile["params"] = h5py.ExternalLink(relative_link_target,
"params")
                h5_outfile["info"] = h5py.ExternalLink(relative_link_target,
"info")
                h5_outfile["misc"] = h5py.ExternalLink(relative_link_target,
"misc")
                h5_outfile["version"] = h5py.ExternalLink(relative_link_target,
"version")

            for key in h5_infile['data']:

                # Link in the data.
                ds_path = "data/%s" % (key)
                h5_outfile[ds_path] = h5py.ExternalLink(relative_link_target,ds_path)

            # Close input file.
            h5_infile.close()

        # Close file.
        h5_outfile.close()

        # Reset output path.
        self.output_path = self.output_path+".h5"



