#https://www.studytonight.com/python/python-threading-condition-object
#gedit font preferences Source Code Pro
'''
Note: the notify() and notifyAll() methods don’t release the lock; this means that the thread or threads awakened will not return from their wait() call immediately, but only when the thread that called notify() or notifyAll() finally relinquishes ownership of the lock.ownership of the lock.
'''

from threading import Thread, Condition
import time
from random import random

queue = []
MAX_NUM, i= 10, 0
condition  = Condition() #creates a default lock

class ProducerThread(Thread):
	print("**Start Producer**")
	def run(self):
		global queue, i
		while True:
			condition.acquire() #returns true and producer aquires default lock
			print("\nProducer Aquires lock...")
			if len(queue) == MAX_NUM:
				print("\n>>Queue full, producer is waiting..\n")
				print("Producer Suspended...")
				condition.wait() #releases the lock and blocks the producer thread
				print("Producer Woken...")
				print("\n\"Queue Freed\" - Consumer notifies the Producer**\n")
			queue.append(round(random()*10,2))
			print("Produced",queue[i],"kB of Data")
			i+=1
			condition.notify()
			condition.release()
			print("Producer Releases lock...")
			time.sleep(1)

class ConsumerThread(Thread):
	print("\n**Start Consumer**")
	def run(self):
		global queue, i
		while True:
			condition.acquire() #returns true and consumer aquires default lock
			print("\nConsumer Aquires lock...")
			if not queue: #queue not empty if produer has produced something
				print("\n>>Nothing in queue, consumer is waiting..\n")
				print("Consumer Suspended...")
				condition.wait() #releases the lock and blocks the consumer thread
				print("Consumer Woken...")
				print("\n\"Queue Occupied\" - Producer notifies the Consumer\n")
			val = queue.pop(i-1)
			i-=1
			print("Consumed",val,"kB of Data")
			condition.notify()
			condition.release()
			print("Consumer Releases lock...")
			time.sleep(1)


ProducerThread().start()
ConsumerThread().start()

'''
condition.wait()
	#This method is used to block the thread and make it wait until some other thread notifies it by calling the notify() or notifyAll()	method on the same condition object or until the timeout occurs.

	#This method returns True if it is released because of notify() or	notifyAll() method else if timeout occurs this method will returnFalse boolean value.

	#The control here goes to ConsumerThread.start()
'''
