import ChargeEntry_ext as ce
import sys
import random

print("---------------------------------------------------------------------")
print("Testing ChargeEntry")
print(" ")

# Initiate
print("instantiate")
o = ce.ChargeEntry()
print(type(o))
print(" ")

# get the value
print("testing the getter")
print("current value: " + str(o.getCharge()))
if o.getCharge() != 0:
	print("Charge aofter init should be 0")
	sys.exit(1)
print(" ")

# set a value
val = random.uniform(-100,100)
print("Setting charge to: " + str(val))
o.setCharge(val)
print("current value: " + str(o.getCharge()))
if o.getCharge() != val:
	print("charge should be: "+ str(val))
	sys.exit(1)
print(" ")

# add value to the charge
val = random.uniform(-100,100)
nval = o.getCharge() + val
print("Adding to charge: " + str(o.getCharge()) + " a value of " + str(val) +
", new charge should be: " + str(nval) )
o.addCharge(val)
print("current value: " + str(o.getCharge()))
if o.getCharge() != nval:
	print("charge should be: "+ str(nval))
	sys.exit(1)
print(" ")

print("-----------------------------------------------------------------------")
print("ChargeEntry successfully checked")
print(" ")
