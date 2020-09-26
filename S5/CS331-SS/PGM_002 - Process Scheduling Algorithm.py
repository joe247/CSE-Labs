#pip3 install beautifultable

from beautifultable import BeautifulTable
from random import sample

def waitTurnNonPreemption():
	twt, ttt = 0, 0
	bT.insert_column(4, "Start Time", [0]*n)
	bT.insert_column(5, "Waiting Time", [0]*n)
	bT.insert_column(6, "Turnaround Time", [0]*n)
	for i in range(n):
		bT[i]["Start Time"] = bT[i]["Arrival Time"] if i==0 else bT[i-1]["Start Time"] + bT[i-1]["Burst Time"]
		if bT[i]["Arrival Time"] > bT[i-1]["Burst Time"]:
			bT[i] ["Start Time"] = bT[i]["Arrival Time"]
		bT[i]["Waiting Time"] = 0 if i==0 else bT[i]["Start Time"] - bT[i]["Arrival Time"]
		bT[i]["Turnaround Time"] = bT[i]["Burst Time"] if i==0 else bT[i]["Burst Time"] + bT[i]["Waiting Time"]
		ttt += bT[i]["Turnaround Time"]
		twt += bT[i]["Waiting Time"]
	bT.sort("Arrival Time")
	print(bT)
	print("\nAverage Waiting Time:", round(twt/n,2),"ms")
	print("Average Turnaround Time:", round(ttt/n,2),"ms")

def nonPreemptiveScheduling(flag):
	#Arrival Time is nullified everywhere except for FCFS
	if flag == 1:
		#Priority
		print("\nPriority Scheduling\n")
		bT["Arrival Time"] = [0]*n
		bT.sort("Priority")
		waitTurnNonPreemption()
	elif flag == 2:
		#SJF Scheduling
		print("\nSJF Scheduling\n")
		bT["Arrival Time"] = [0]*n
		bT.sort("Burst Time")
		waitTurnNonPreemption()
	else:
		#FCFS Scheduling
		print("\nFCFS Scheduling\n")
		bT.sort("Arrival Time")
		waitTurnNonPreemption()

def roundRobinScheduling():
		#RR Scheduling
		bT.sort("Arrival Time")
		remn_btime, lst = [], []
		twt, ttt, crnt_time, done = 0, 0, bT[0]["Arrival Time"], False
		bT.insert_column(5, "Waiting Time", [0]*n)
		bT.insert_column(6, "Turnaround Time", [0]*n)
		print("\nRR Scheduling\n")
		time_slice = int(input("Enter a time quantum: "))
		for i in range(n):
			remn_btime.append(bT[i]["Burst Time"])
			lst.append(bT[i]["Arrival Time"])
		while not done:
			for i in range(n):
				if remn_btime == [0]*n:
					done = True
				elif remn_btime[i] > time_slice:
					bT[i]["Waiting Time"] += crnt_time - lst[i]
					crnt_time += time_slice
					lst[i] = crnt_time
					remn_btime[i] -= time_slice
				elif remn_btime[i] > 0:
					bT[i]["Waiting Time"] += crnt_time - lst[i]
					crnt_time += remn_btime[i]
					lst[i] = crnt_time
					remn_btime[i] = 0
		for i in range(n):
			bT[i]["Turnaround Time"] += bT[i]["Burst Time"] + bT[i]["Waiting Time"]
			ttt += bT[i]["Turnaround Time"]
			twt += bT[i]["Waiting Time"]

		print(bT)
		print("\nAverage Waiting Time:", round(twt/n,2),"ms")
		print("Average Turnaround Time:", round(ttt/n,2),"ms")

def selectSchedulingMenu():
	print("\nSelect Scheduling Algorithm: ")
	x = int(input("\n1. Round Robin (Preemptive)\n2. Non-Preemptive: "))
	if x == 1:
		roundRobinScheduling()
	elif x  in [1,2]:
		y = int(input("\n1. Priority\n2. Shortest Job First\n3. First Come First Serve: "))
		nonPreemptiveScheduling(y) if y in [1,2,3] else print("Invalid Input")
	else:
		print("Option",x," not found!")

def setProcessQueue():
	bT.column_headers = ["Process ID", "Arrival Time", "Burst Time", "Priority"]
	for i in range(n):
		bT.append_row(["P"+str(at[i]), at[i], bt[i], pt[i]])
	print(bT)
	selectSchedulingMenu()

def manualPC():
	global n, at, bt, pt
	n = int(input("\nEnter number of process: "))
	for i in range(n):
		print("\n#For process",i)
		at.append(int(input("Arrival Time: ")))
		bt.append(int(input("Burst Time: ")))
		pt.append(int(input("Priority: ")))
	setProcessQueue()

def autoPC():
	global n, at, bt, pt
	n = sample(range(1,11),1)[0]
	at = sample(range(11),n)
	bt = sample(range(1,21),n)
	pt = sample(range(1,11),n)
	setProcessQueue()

def processCreation():
	print("\nSelect type of process creation: ")
	pc = int(input("1. Manual\n2. Automated: "))
	if pc in [1,2]:
		manualPC() if pc == 1 else autoPC()
	else:
		print("Option",pc,"not found!")

n, at, bt, pt = 0, [], [], []
bT=BeautifulTable()
processCreation()
'''
n = 4
at = [2,3,6,7]
bt = [14,2,7,11]
pt = [3,10,4,2]
setProcessQueue()
'''
