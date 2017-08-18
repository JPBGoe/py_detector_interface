import ChargeSim_ext as cs
import InteractionData_ext as iae
import ChargeMatrix_ext as cme
import sys
import random


def error(o):
	print(o)
	sys.exit(1)	

correct = True

print("-----------------------------------------------------------------------")
print(" Test ChargeSim ")
print(" ")

print("Instantiate")
o = cs.ChargeSim()
print(type(o))
print(" ")

print("create instances for input and output")
i = iae.InteractionData()
c = cme.ChargeMatrix()
c.clear()
c.setSize(1,1)
print(type(i))
print(type(c))
print(" ")

print("set the input")
try:
	o.setInput(i)
except Exception as ex:
	print("Exceptions with found:")
	print(ex)
	correct = False
print(" ")

plasmasearch = ["BLANK"]
pointsim = ["FULL","FANO","BINNING"] # "LUT"
plasmasim = ["BLANKPLASMA"]
detect = ["pnCCD", "LPD" , "AGIPD", "AGIPDSPB"]

print("set components")
for ps in plasmasearch:
	for psim in pointsim:
		for psi in plasmasim:
			for det in detect:
				print("(" + str(ps) + "," + str(psim) + "," + str(psi) + "," + str(det) + ")")
				o.setComponents(c,ps,psim,psi,det)
print(" ")


print("Testing failures")
print("plasmasearch")
try:
	o.setComponents(c,"hello",psim,psi,det)
	error("hello as plasmasearch should produce an exception")
except Exception:
	print("successful")
print("pointsim")
try:
	o.setComponents(c,ps,"hello",psi,det)
	error("hello as pointsim should produce an exception")
except Exception:
	print("successful")
print("plasmasim")
try:
	o.setComponents(c,ps,psim,"hello",det)
	error("hello as plasmasim should produce an exception")
except Exception:
	print("successful")
print("detector")
try:
	o.setComponents(c,ps,psim,psi,"hello")
	error("hello as detector should produce an exception")
except Exception:
	print("successful")
print(" ")


print("Start the simulation")
try:
	o.runSimulation()
except Exception as ex:
	print("Exception caught:")
	print(ex)
	correct = False
print(" ")

if correct == False:
	error("There might be some errors")

print("----------------------------------------------------------------------")
print("Test of ChargeSim finished")
print(" " )
