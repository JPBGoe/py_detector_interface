#!/usr/bin/python
import PhotonEntry_ext as pe
import random


print("Testing PhotonEntry")
print("--------------------------------------------")
print("Instantiate")
o=pe.PhotonEntry()
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

# Testing the director setters and getters
print("initial direction in x,y,z: " + str(o.getDirectionX()) + ", " +
	str(o.getDirectionY()) + ", " + str(o.getDirectionZ()))
r1 = random.uniform(-1000,1000)
r2 = random.uniform(-1000,1000)
r3 = random.uniform(-1000,1000)
print("change directions to " + str(r1) + "," + str(r2) + "," + str(r3))
o.setDirectionX(r1)
o.setDirectionY(r2)
o.setDirectionZ(r3)
print("new direction in x,y,z: " + str(o.getDirectionX()) + ", " +
	str(o.getDirectionY()) + ", " + str(o.getDirectionZ()))
if(o.getDirectionX() != r1 or o.getDirectionY() != r2 or o.getDirectionZ() != r3):
	error("direction getters or setters produce problems")
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

# Testing set
print("testing set method")
r1 = random.uniform(-1000,1000)
r2 = random.uniform(-1000,1000)
r3 = random.uniform(-1000,1000)
r4 = random.uniform(-1000,1000)
r5 = random.uniform(-1000,1000)
r6 = random.uniform(-1000,1000)
r7 = random.uniform(-1000,1000)
print("set energy to: " + str(r1))
o.setEnergy(r1)
print("set position to: " + str(r2) + ","+ str(r3) + "," + str(r4))
o.setPositionX(r2)
o.setPositionY(r3)
o.setPositionZ(r4)
print("set direction to: " +str(r5) + ","+ str(r6) + "," + str(r7))
o.setDirectionX(r5)
o.setDirectionY(r6)
o.setDirectionZ(r7)
print("new energy: " + str(o.getEnergy()))
if(o.getEnergy() != r1):
	error("energy setter or getter produce problems")
print("new position x,y,z: " + str(o.getPositionX()) + ", " +
	str(o.getPositionY()) + ", " + str(o.getPositionZ()))
if(o.getPositionX() != r2 or o.getPositionY() != r3 or o.getPositionZ() != r4):
	error("position getters or setters produce problems")
print("new direction in x,y,z: " + str(o.getDirectionX()) + ", " +
	str(o.getDirectionY()) + ", " + str(o.getDirectionZ()))
if(o.getDirectionX() != r5 or o.getDirectionY() != r6 or o.getDirectionZ() != r7):
	error("direction getters or setters produce problems")
print(" ")



print("--------------------------------------------")
print("Test of PhotonEntry_ext successful completed")




