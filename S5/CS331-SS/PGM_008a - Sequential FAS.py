## Sequential
from termcolor import colored

size, mem = [], list(range(50))
files = ['F1', 'F2', 'F3', 'F4']
size = [[0, 10], [23, 3], [30, 7], [45, 5]]

#files = list(map(str, input('Enter file name: ').split()))

print('Free Memory:')
[print(i, end ='\n' if (mem.index(i)+1)%10 == 0 else ' ') for i in mem]

#for i in files:
#	size.append(list(map(int, input('Enter start address & size of file '+i+' : ').split())))

dirc = dict(zip(files, size))

for i in dirc:
	f_start = dirc[i][0]
	for j in range(f_start, f_start+dirc[i][1]):
		mem[j] = i
		f_start = j+1

print('\nMemory after file allocation:')
[print(colored(i, 'cyan') if i==str(i) else i, end='\n' if (k+1)%10 == 0 else ' ') for i, k in zip(mem, range(len(mem)))]
print()
