'''
Non Blocking does not mean philosophers will starve, that's dead-lock. "Non Blocking" means there is no "stop and wait for something to happen"

Lock has two basic methods, acquire() and release()

>>> When the state is "unlocked", acquire() changes the state to locked and returns immediately.

>>>When the state is locked, acquire() blocks until a call to release() in another thread changes it to unlocked, then the acquire() call resets it to locked and returns.

>>>The release() method should only be called in the locked state; it changes the state to unlocked and returns immediately. If an attempt is made to release an unlocked lock, a RuntimeError will be raised.
'''
from threading import Thread, Lock
from matplotlib import pyplot as plt
from time import sleep
from random import random


class Philosopher(Thread):
	running = True
	def __init__(self, xname, leftFork, rightFork):
		Thread.__init__(self)
		self.name = xname
		self.LFork = leftFork
		self.RFork = rightFork
	def run(self):
		while self.running:
			sleep(random()*10)
			print(self.name,"is hungry and thinking ...")
			self.dine()
	def dine(self):
		forkL, forkR = self.LFork, self.RFork
		while self.running:
			forkL.acquire(True)
			locked = forkR.acquire(False)
			if locked: break
			forkL.release() #No hold and wait Phil!
			forkL, forkR = forkR, forkL  # Swap the forks, so that next time you acquire the right fork first
		else:
			return
		self.dining()
		forkL.release()
		forkR.release()
	def dining(self):
		print(self.name, "start eating...")
		sleep(random()*10)
		print(self.name, "finishes eating\n")

def DiningPhilosophers():
		philosophers = [Philosopher(philosophersName[i], forks[i%5], forks[(i+1)%5]) for i in range(5)]
		#Philosopher.running = True
		for p in philosophers: p.start()
		sleep(10)
		Philosopher.running = False

def updatePlot():
	plt.pie(portion, labels=philosophersName)
	plt.draw()

if __name__ == "__main__":
	forks = [Lock() for i in range(5)] #creates 5 unlocked, _thread.lock, object
	philosophersName, portion = ["Aristotle", "Plato","Jovial", "Russel", "CS Lewis"], [20]*5
	updatePlot()
	print("Our Philosphers...")
	for i in range(len(philosophersName)): print(str(i+1)+". "+philosophersName[i])
	DiningPhilosophers()
	plt.show()
