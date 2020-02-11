#! /bin/bash
# String palindrome 09
echo -n "Enter a string: "
read str
res=""
len=${#str}
for ((i=$len-1; i>=0; i--)) do
	res+=${str:$i:1}
done
if [[ $str == $res ]] then
	echo "Yes"
else
	echo "No"
fi
