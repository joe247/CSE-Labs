import numpy as np # to run this make sure you have numpy library. To install run (on terminal): pip install numpy

n_processes = int(input('Number of processes > '))
n_resources = int(input('Number of resources > '))

available_resources = [int(x) for x in input('Claim vector? ').split(' ')]

currently_allocated = np.array(
    [[int(x) for x in input('Currently allocated for process ' + str(i + 1) + '? ').split(' ')] for i in
     range(n_processes)])
max_demand = np.array([[int(x) for x in input('Maximum demand from process ' + str(i + 1) + '? ').split(' ')] for i in
                       range(n_processes)])

total_available = available_resources - np.sum(currently_allocated, axis=0)

running = np.ones(n_processes)  # An array with n_processes 1's to indicate if process is yet to run

while np.count_nonzero(running) > 0:
	at_least_one_allocated = False
	for p in range(n_processes):
		if running[p]:
			if all(i >= 0 for i in total_available - (max_demand[p] - currently_allocated[p])):
				at_least_one_allocated = True
				print(str(p) + ' is running')
				running[p] = 0
				total_available += currently_allocated[p]
	print('Current Allocation: ')
	[print(s) for s in available_resources]
	print('Max Demand: ')
	[print(*s) for s in max_demand]
	print('Total Available')
	[print(s if s > 0 else 0) for s in total_available]
	if not at_least_one_allocated:
		print('Status: Unsafe')
		exit()

print('Status: Safe')

'''
My method!
#Banker's Algorithm from scratch
from termcolor import colored
from random import random
n = int(input('Enter number of processes: '))
m = int(input('Enter number of resources: '))

processes = []
resources = []
[processes.append('P'+str(i+1)) for i in range(n)]
[resources.append('R'+str(i+1)) for i in range(m)]

print('System Processes: ', end='')
[print(colored(i,'cyan'), end=' ') for i in processes]
print('\nSystem Resources: ', end='')
[print(colored(i,'yellow'), end=' ') for i in resources]


print('\n\nWarning!\nEach process MUST DECLARE the maximum number of instances of each resource type that it may ever claim, this SHOULD NOT EXCEED the total number for resource instances, for the proper functioning of the program.\n\n')


resource_instances = {}
for i in resources:
	resource_instances[i] = int(input('Enter number of instances for the resource: '+i+' : '))

claim_vector = {}
for i in processes:
		claim_vector[i] = list(map(int, input('Enter claim vector of process '+i+' : ').split()))

allocated = {}
for i in processes:
		allocated[i] = list(map(int, input('Enter resource instances for process '+i+' : ').split()))
		
available = {}
for i, j in zip(resources_instances, allocated):
	available[i] = resource_instances[i] - allocated[j]
'''
