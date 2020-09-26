#! /bin/bash
# Shell calculator 05
echo -n "Operand A: "
read a
echo -n "Operator: "
read o
echo -n "Operand B: "
read b
echo -n "The expression: $a $o $b = "
if [[ $o == "/" && $b == 0 ]] then
	echo "Can't divide by zero."
else
	echo $((a $o b))
fi

