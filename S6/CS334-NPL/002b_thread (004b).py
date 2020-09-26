# Python code to create threads
import threading
import time

def dummy():
	pass

def main():
	for i in range(5):
		tid = threading.Thread(target=dummy, args=[])
		print (f'Created new thread {tid} {threading.get_ident()}')
		time.sleep(1)

if __name__ == '__main__':
	main()
