import libpy_detector_interface as lpdi

print("-----------------------------------------------------------------------")
print("testing function of ParticleSim exports")
print(" ")

print("instantiate a simulation")
o = lpdi.ParticleSim()
print(type(o))
print(" ")

print("calling the initialization method")
detectors =["pnCCD","LPD","AGIPD","AGIPDSPB"] # CAD
for i in detectors:
	print("Init with " + str(i))
	o.initialization(i)
print("all detector names can be set")
print(" ")

print("calling the runSimulation method with parameters")
p = lpdi.PhotonData()
print(type(p))
o.setInput(p)

i = lpdi.InteractionData()
print(type(i))
o.setOutput(i)

o.runSimulation()
print("simulation can be executed")
print(" ")

print("------------------------------------------------------------------------")
print("test of ParticleSim finished")


