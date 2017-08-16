import ChargeMatrix_ext as cm
import ChargeEntry_ext as ce
import sys
import random

# Combination to test the ChargeMatrix ChargeEntry complex

def error(o):
	print(o)
	sys.exit(1)


print("-----------------------------------------------------------------------")
print(" Testing ChargeMatrix and ChargeMatrixEntry")
print(" ")

# Test the ChargeMatrix constructor
print("init of parameterless constructor")
o = cm.ChargeMatrix()
print(type(o))
print(" ")

# Test the size and
print("Testing the size functions:")
print(" x = " + str(o.width()))
print(" y = " + str(o.height()))
if (o.width() != 1 or o.height() != 1):
	error("Size should be 0 x 0")
print(" ")

# testing to set a size
v1 = random.randint(1,10)
v2 = random.randint(1,10)
print("Setting the new size to " + str(v1) + " x " + str(v2))
o.clear()
o.setSize(v1,v2)
print(" x = " + str(o.width()))
print(" y = " + str(o.height()))
if (o.width() != v1 or o.height() != v2):
	error("Size should be " + str(v1) + " x " + str(v2))
print(" ")

print("try to produce an error during setSize")
try:
	o.setSize(0,4)
	error("You souldn't be able to set a <= 0 value as dim")
except Exception:
	print("application successfully failed")
print(" ")

print("try to access an element out of bound")
try:
	o.getEntry(10,10)
	error("out of bounds exception should have been thrown")
except Exception:
	print("out of bounds successfully tested")
print(" ")

print("accessing an element, setting its charge to 4, add 2")
n1 = random.randint(0,v1-1)
n2 = random.randint(0,v2-1)
ce = o.getEntry(n1,n2)
print("element: " +str(n1) + " x " + str(n2) + " is ")
print(type(ce))
ce.setCharge(4)
ce.addCharge(2)
print("charge: " + str(ce.getCharge()))
print(" ")

print("accessing another element, setting its charge to 1, add 10")
a1 = random.randint(0,v1-1)
a2 = random.randint(0,v2-1)
ce = o.getEntry(a1,a2)
print("element: " +str(a1) + " x " + str(a2) + " is ")
print(type(ce))
ce.setCharge(1)
ce.addCharge(10)
print("charge: " + str(ce.getCharge()))
print(" ")

print("Check the first element again")
t = o.getEntry(n1,n2)
print("charge: " + str(t.getCharge()))
if(t.getCharge() != 6):
	error("incorrect charge")
print("Check the second element again")
t = o.getEntry(a1,a2)
print("charge: " + str(t.getCharge()))
if(t.getCharge() != 11):
	error("incorrect charge")
print( " " )

print("Calling clear and trying to access the first element")
o.clear()
print(" x = " + str(o.width()))
print(" y = " + str(o.height()))
try:
	o.getEntry(n1,n2)
	error("There souldn't be any elements left")
except Exception:
	print("clear successful")

print("-----------------------------------------------------------------------")
print(" Testing ChargeMatrix and ChargeMatrixEntry successful")

