'''
request_list = [13, 43, 153, 12, 53, 122, 80, 147, 130]
head = 100
print(request_list)
print(head,'\n')
'''

from bisect import bisect_left

def get_closest(rl, hd): #get closest using binary search
	pos = bisect_left(rl, head)
	if pos == len(rl):
		return rl[-1]
	before = rl[pos - 1]
	after = rl[pos]
	if after - head > head - before: #returns closest larger value
		return after
	else:
		return before

def FCFS():
	print('Algorithm: FCFS')
	
	hd = head
	rl = request_list.copy()
	if 0 not in rl:
		rl.insert(0, 0)
	if 200 not in rl:
		rl.append(200)
	
	displacement=[]
	
	print('Head movement:', end =' ')
	for i in rl:
		print(i, end = ' >> ' if rl.index(i) < len(rl)-1 else '\n')
		displacement.append(abs(hd-i))
		hd = i
	print('Average head movement: ', round(sum(displacement)/len(displacement), 2), 'sectors')

def XCAN(x):
	print('\nAlgorithm: SCAN' if x == 0 else '\nAlgorithm: CSCAN')
	
	hd = head
	rl = request_list.copy()
	rl.sort()
	if 0 not in rl:
		rl.insert(0, 0)
	if 200 not in rl:
		rl.append(200)
	
	val = get_closest(rl, hd)
	displacement=[]
	sav = val
	
	print('Head movement:', end =' ')
	#phase 1:
	p1 = rl[rl.index(val):]
	for i in p1:
		print(i, end = ' >> ')
		displacement.append(abs(val-i))
		val = i
	val = sav
	#phase 2:
	p2 = rl[:rl.index(val)] if x == 0 else rl[rl.index(val)+1::-1]
	for i in p2:
		print(i, end = ' >> ' if p2.index(i) < len(p2)-1 else '\n')
		displacement.append(abs(val-i))
		val = i
	print('Average head movement: ', round(sum(displacement)/len(displacement), 2), 'sectors')

request_list = list(map(int, input('Enter the requests [0 - 200]: ').split()))
for i in request_list:
	if 0 > i  or i > 201:
		print(i, 'not in range hence removed')
		request_list.remove(i)

head = int(input('Enter the initial location of head: '))
while head not in range(0,201):
	print('Invalid head value!')
	head = int(input('Enter the initial location of head: '))
FCFS()
[XCAN(x) for x in [0,1]]
