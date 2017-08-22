import PhotonData_ext as pd
import PhotonEntry_ext as pe
import sys

print("Testing PhotonData_ext module")
print("-----------------------------------------------------------------------")

# Create a new instance
print("Instantiating")
o = pd.PhotonData()
print(type(o))
print("instance created")
print(" ")

# checking the size of the new instance
print("initial size should be 0")
print("size: " + str(o.size()))
if o.size() != 0:
	print("initial size should be 0")
	sys.exit(1)
print(" ")

# store a first element
print("creating an instance")
ne = o.addEntry()
print("instance of the created obj: " + str(type(ne)))
print("size: " + str(o.size()))
if o.size() != 1:
	print("after one init size should be 1")
	sys.exit(1)
print("setting new instance positions to 4.0 2.0 4.2")
ne.setPositionX(4.0)
ne.setPositionY(2.0)
ne.setPositionZ(4.2)

# store a second element
print("create another new instance")
ne = o.addEntry()
print("instance of the created obj: " + str(type(ne)))
print("size: " + str(o.size()))
if o.size() != 2:
	print("after one init size should be 2")
	sys.exit(1)
print("setting new instance with directions 1 -1 0")
ne.setDirectionX(1)
ne.setDirectionY(-1)
ne.setDirectionZ(0)
print(" ")

# accessing the first element
print("accessing the first created entry with index 0")
ae = o.getEntry(0)
print("type of the accessed entry: " + str(type(ae)))
print("(" + str(ae.getPositionX()) + "," + str(ae.getPositionY()) + "," +
str(ae.getPositionZ()) + "),(" + str(ae.getDirectionX()) + "," +
str(ae.getDirectionY()) + "," + str(ae.getDirectionZ()) + "),E=" +
str(ae.getEnergy()))
if (ae.getPositionX() != 4.0 or ae.getPositionY() != 2.0 or 
	ae.getPositionZ() != 4.2 or ae.getDirectionX() != 0 or ae.getDirectionY()!=0
	or ae.getDirectionZ() != 0 or ae.getEnergy() != 0):
	print("init values of instance do not match returned values")
	sys.exit(1)

# accessing the second element
print("accessing the second created entry with index 1")
ae = o.getEntry(1)
print("type of the accessed entry: " + str(type(ae)))
print("(" + str(ae.getPositionX()) + "," + str(ae.getPositionY()) + "," +
str(ae.getPositionZ()) + "),(" + str(ae.getDirectionX()) + "," +
str(ae.getDirectionY()) + "," + str(ae.getDirectionZ()) + "),E=" +
str(ae.getEnergy()))
if (ae.getPositionX() != 0 or ae.getPositionY() != 0.0 or 
	ae.getPositionZ() != 0 or ae.getDirectionX() != 1 or ae.getDirectionY()!=-1
	or ae.getDirectionZ() != 0 or ae.getEnergy() != 0):
	print("init values of instance do not match returned values")
	sys.exit(1)

# accessing out of bounds
print("producing an error by trying to access index 2")
try:
	ae = o.getEntry(2)
	print("you should not be allowed to all index 2 at 2 elements")
	sys.exit(1)
except Exception:
	print("accessing failed successful")
print("producing an error by trying to access index -1")
try:
	ae = o.getEntry(-1)
	print("you should not be allowed to access elements of negative index")
	sys.exit(1)
except Exception:
	print("accessing successfully failed")
print(" ")

# clearing the data container
print("clearing the data storage")
o.clear()
print("size: " + str(o.size()))
print("try to access the index 0 element")
try:
	ae = o.getEntry(0)
	print("there shouldn't be elements accessable after clear")
	sys.exit(1)
except Exception:
	print("accessing successfully failed")
if o.size() != 0:
	print("there shouldn't be any elements in the container")
	sys.exit(1)

print("-----------------------------------------------------------------------")
print("Test of PhotonData successfully completed")





