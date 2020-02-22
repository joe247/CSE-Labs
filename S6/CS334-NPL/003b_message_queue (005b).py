import multiprocessing
from time import sleep

def square_list(mylist, q):
	print('From process p1 ... creating squared queue')
	"""	function to square a given list """
	# append squares of mylist to queue
	for num in mylist:
		q.put(num * num)
	print(f'Queue: {mylist[:]}\n')

def print_queue(q):
	""" function to print queue elements """
	print('From process p2 ... retriving squared queue')
	print("Queue elements: ", end='')
	while not q.empty():
		print(q.get(), end=' ')
	print("\nQueue is now empty!")

if __name__ == "__main__":
	# input list
	mylist = [1,2,3,4]

	# creating multiprocessing Queue
	q = multiprocessing.Queue()

	# creating new processes
	p1 = multiprocessing.Process(target=square_list, args=(mylist, q))
	p2 = multiprocessing.Process(target=print_queue, args=(q,))

	# running process p1 to square list
	p1.start()
	p1.join()

	# running process p2 to get queue elements
	p2.start()
	p2.join()
