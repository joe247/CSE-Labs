#! /bin/bash
# Positive or negative 02
echo -n "Enter a number: "
read x
if ((x>0)) then
	echo "+ve"
else
	echo "-ve"
fi
