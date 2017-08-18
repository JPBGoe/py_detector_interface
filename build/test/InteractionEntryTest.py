#!/usr/bin/python
import InteractionEntry_ext as iae
import random


print("Testing InteractionEntry")
print("--------------------------------------------")
print("Instantiate")
o=iae.InteractionEntry()
print(type(o))


# Testing the position setters and getters
print("initial position x,y,z: " + str(o.getPositionX()) + ", " +
	str(o.getPositionY()) + ", " + str(o.getPositionZ()))
r1 = random.uniform(-1000,1000)
r2 = random.uniform(-1000,1000)
r3 = random.uniform(-1000,1000)
print("change positions to " + str(r1) + "," + str(r2) + "," + str(r3))
o.setPositionX(r1)
o.setPositionY(r2)
o.setPositionZ(r3)
print("new position x,y,z: " + str(o.getPositionX()) + ", " +
	str(o.getPositionY()) + ", " + str(o.getPositionZ()))
if(o.getPositionX() != r1 or o.getPositionY() != r2 or o.getPositionZ() != r3):
	error("position getters or setters produce problems")
print(" ")

# Testing the energy setters and getters
print("initial energy: " + str(o.getEnergy()))
r1 = random.uniform(-1000,1000)
o.setEnergy(r1)
print("change energy to " + str(r1))
print("new energy: " + str(o.getEnergy()))
if(o.getEnergy() != r1):
	error("energy setter or getter produce problems")
print(" ")

# Testing the time setters and getters
print("initial time: " + str(o.getTime()))
r1 = random.uniform(-1000,1000)
o.setTime(r1)
print("change time to " + str(r1))
print("new time: " + str(o.getTime()))
if(o.getTime() != r1):
	error("time setter or getter produce problems")
print(" ")

# Testing set
print("testing set method")
r1 = random.uniform(-1000,1000)
r2 = random.uniform(-1000,1000)
r3 = random.uniform(-1000,1000)
r4 = random.uniform(-1000,1000)
r5 = random.uniform(-1000,1000)
print("set energy to: " + str(r1))
o.setEnergy(r1)
print("set time to: " + str(r2))
o.setTime(r2)
print("set position to: " +str(r3) + ","+ str(r4) + "," + str(r5))
o.setPositionX(r3)
o.setPositionY(r4)
o.setPositionZ(r5)
print("new energy: " + str(o.getEnergy()))
if(o.getEnergy() != r1):
    error("energy setter or getter produce problems")
print("new time:  " + str(o.getTime()))
if(o.getTime() != r2):
    error("time getter or setter produce problems")
print("new position in x,y,z: " + str(o.getPositionX()) + ", " +
    str(o.getPositionY()) + ", " + str(o.getPositionZ()))
if(o.getPositionX() != r3 or o.getPositionY() != r4 or o.getPositionZ() !=
r5):
    error("direction getters or setters produce problems")
print(" ")



print("--------------------------------------------")
print("Test of InteractionEntry_ext successful completed")




