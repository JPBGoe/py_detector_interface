import ParticleSim_ext as ps
import PhotonData_ext as pde
import InteractionData_ext as ide

print("-----------------------------------------------------------------------")
print("testing function of ParticleSim exports")
print(" ")

print("instantiate a simulation")
o = ps.ParticleSim()
print(type(o))
print(" ")

print("calling the initialization method")
detectors =["pnCCD","LPD","AGIPD","AGIPDSPB","CAD"]
for i in detectors:
	o.initialization(i)
print("all detector names can be set")
print(" ")

print("calling the runSimulation method with parameters")
p = pde.PhotonData()
print(type(p))
i = ide.InteractionData()
print(type(i))
o.runSimulation(p,i)
print("simulation can be executed")
print(" ")

print("------------------------------------------------------------------------")
print("test of ParticleSim finished")


