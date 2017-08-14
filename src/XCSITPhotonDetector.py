import PhotonEntry_ext
import PhotonData_ext
import InteractionEntry_ext
import InteractionData_ext
import ParticleSim_ext

class XCSITPhotonDetector(AbstractPhotonDetector):
	
	# Attributes of the abstract class
	__expected_data
	__provided_data
	__input_path
	__output_path

	# Attributes to save the data containers
	__photon_data	# PhotonData_ext
	__ia_data		# InteractionData_ext
	__charge_data	# ChargeMatrx_ext


	# Parameters of the simulation
	__detectorname

	__init__(self,parameters=None,input_path=None,output_path=None):
		if input_path== None:
			error("input_path of the hdm5 file has to be specified")
		
		if output_path== None:
			error("output_path of the resulting hdm5 file has to be specified")

		self.__input_path = input_path
		self.__output_path= output_path

	expectedData(self):
		return self.__expectedData

	providedData(self):
		return self.__providedData

	getChargeData(self):
		return self.__charge_data

	getInteractionData(self):
		return self.__ia_data

	getPhotonData(self):
		return self.__photon_data

	__createXCSITInteractions(self):
		pass

	__createXCSITChargeMatrix(self):
		pass


	__backenginIA(self,photons=None,interactions=None):
		# Check fro input containers
		if photons == None:
			error("Cannot make a photon interaction simulation without photons")
		if interactions== None:
			error("Container needs to be provided to store the resulting"
				"interactions")
	
		# Run the simulation
		ps = ParticleSim_ext.ParticleSim()
		ps.initialization(self.__detectorname)
		ps.runSimulation(photons,interactions)
		
		
		# Return the container with the Interactions
		return interactions

	__backengineCP(self,interactions=None,chargeMatrix=None):
		pass

	backengine(self):
		print("Simulating photon-detector interaction")
		# Create the containers
		self.__ia_data 		= self.__createXCSITInteractions(self)
		self.__charge_data	= self.__createXCSITChargeMatrix(self)

		# run the particle simulation
		self.__ia_data 	=
			self.__backengineIA(self,self.__photon_data,self.__ia_data)
		print("Interaction simulation of the detector is finished")

		# run the charge simulation
		self.__charge_data =
			self.__backengineCP(self,self.__ia_data,self.__charge_data)		
		print("Charge propagation simulation in the detector is finished")


	_readH5(self):
		pass

	saveH5(self):
		pass
