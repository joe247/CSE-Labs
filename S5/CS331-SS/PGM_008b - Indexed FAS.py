## Sequential
from termcolor import colored

size, mem = [], list(range(50))
files = ['F1', 'F2', 'F3', 'F4']
size = [[10, 30, 12, 13], [14, 16], [34, 37, 40], [36]]

#files = list(map(str, input('Enter file name: ').split()))

print('Free Memory:')
[print(i, end ='\n' if (mem.index(i)+1)%10 == 0 else ' ') for i in mem]


#for i in files:
#	size.append(list(map(int, input('Enter start address & size of file '+i+' : ').split())))

dirc = dict(zip(files, size))

for i in dirc:
	for j in dirc[i]:
		mem[j] = i

for i in dirc:
	print('\n'+i)
	print(dirc[i][0], end= ' --> ')
	for j in dirc[i][1:]:
		print ('\t',j)
	print('\tX')
print('\nMemory after file allocation:')
[print(colored(i, 'cyan') if i==str(i) else i, end='\n' if (k+1)%10 == 0 else ' ') for i, k in zip(mem, range(len(mem)))]
print()
