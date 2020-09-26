import csv
print('INPUT\n')
print('INPUT.asm\n=========\n')
with open('input2.csv', newline='') as IPF:  
	reader = csv.reader(IPF)
	for row in reader:
		[print(i, end= '\n' if row.index(i)==3 else '\t') for i in row]
			

print('\n\nOPTAB.db\n========\n')
with open('optab2.csv', newline='') as OPTF:  
    reader = csv.reader(OPTF)
    for row in reader:
        [print(i, end= '\n' if row.index(i)==1 else '\t') for i in row]

print('\n\nOUTPUT\n')
print('\n\nSYMTAB.db\n=========\n')
with open('symtab2.csv', newline='') as SYTF:  
    reader = csv.reader(SYTF)
    for row in reader:
        [print(i, end= '\n' if row.index(i)==1 else '\t') for i in row]

print('\n\nOUTPUT.asm\n=========\n')
with open('output2.csv', newline='') as OPF:  
	reader = csv.reader(OPF)
	for row in reader:
		[print(i, end= '\n' if row.index(i)==4 else '\t') for i in row]
print()