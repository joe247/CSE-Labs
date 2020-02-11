#! /usr/bin/perl
# Perl calculator 07
print("Operand A: ");
$opA = <>;
print("Operator: ");
$opr = <>;
print("Operand B: ");
$opB = <>;
chomp($opA, $opr, $opB);
print("The expression: $opA $opr $opB = ");
if($opr == "/" && $opB == 0){
	print("Can't divide by zero.\n");
}
else{
	print(eval "$opA $opr $opB", "\n");
}

