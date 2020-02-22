# Python code to create child process
import os

def parent_child():
    n = os.fork()
    # n greater than 0 means parent process
    if n:
        print("Parent process and id is = ", os.getpid())
    # n equals to 0 means child process
    else:
        print("Child process and id is = ", os.getpid())

parent_child()
