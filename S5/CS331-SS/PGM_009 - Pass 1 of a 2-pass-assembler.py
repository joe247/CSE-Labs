import csv
print('INPUT\n')
print('INPUT.asm\n=========\n')
with open('input.csv', newline='') as IPF:  
	reader = csv.reader(IPF)
	for row in reader:
		[print(i, end= '\n' if row.index(i)==2 else '\t') for i in row]
			

print('\n\nOPTAB.db\n========\n')
with open('optab.csv', newline='') as OPTF:  
    reader = csv.reader(OPTF)
    for row in reader:
        [print(i, end= '\n' if row.index(i)==1 else '\t') for i in row]

print('\n\nOUTPUT\n')
print('\n\nSYMTAB.db\n=========\n')
with open('symtab.csv', newline='') as SYTF:  
    reader = csv.reader(SYTF)
    for row in reader:
        [print(i, end= '\n' if row.index(i)==1 else '\t') for i in row]
l=[]
print('\n\nOUTPUT.asm\n=========\n')
with open('output.csv', newline='') as OPF:  
	reader = csv.reader(OPF)
	for row in reader:
		[print(i, end= '\n' if row.index(i)==3 else '\t') for i in row]
		[l.append(int(i)) if row.index(i) == 0 and i != '' else 0 for i in row]

print('\nLength of the program =',l[len(l)-1]-l[0])