#! /bin/bash
# Factorial 08
echo -n "Ente a number: "
read x
f=1
echo -n "$x! = "
while ((x>0)) do
	((f*=x))
	((x--))
done
echo "$f"
