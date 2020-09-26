#! /bin/bash
# Smallest of three 04
echo "Enter 3 numbers: "
read x
read y
read z
if ((x<y && x<zn)) then
	echo "$x is smallest."
elif ((y<z)) then
	echo "$y is smallest."
else
	echo "$z is smallest."
fi
