#! /bin/bash
# Sum of digits 10
echo -n "Enter a number: "
read num
sum=0
len=${#num}
for ((i=$len-1; i>=0; i--)) do
	dig=${num:$i:1}
	((sum+=dig))
done
echo "Sum of digits = $sum"
