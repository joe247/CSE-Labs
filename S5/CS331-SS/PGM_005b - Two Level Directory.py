from anytree import Node, RenderTree

def view():
	us, lst = [], []
	rt = Node(root)
	[us.append(Node(i, parent=rt)) for i in users]
	[lst.append(Node(j,parent=i)) for i, k in zip(us, range(len(files))) for j in files[k]]
	for pre, fill, node in RenderTree(rt):
		print(str(pre)+str(node.name))
		fill #just to use the variable

def rem(x):
	global users, files
	name = input('Select User: ')
	if x == 'rmdir' and root and users:
		if name not in users:
			print('None found!')
		else:
			files.pop(users.index(name))
			users.remove(name)
	elif x == 'rm' and root and users:
		rmfil = input("Enter a filename: ")
		if not files or rmfil not in files[users.index(name)]:
			print('None found!')
		else:
			files[users.index(name)].remove(rmfil)
	else:
		print('\nERROR: Root or Users Not Defined!\n')
	view()


def ins(x):
	global users, files
	if x in ['rm', 'rmdir']:
		rem(x)
		return
	elif users:
		y = input('\nWill clear all users!\nContinue (*/N)? : ')
		if y in ['N', 'n']: return
		else: files = []
	users = list(map(str, input("\nEnter the users: ").split()))
	[files.append(list(map(str, input('\nEnter the files for user '+i+' : ').split()))) for i in users]
	view()

def main():
	print("\n###File Organization Commands###")
	x = input('1. mkdir -- makes user directory \n2. rm -- remove a file\n3. rmdir -- removes root folder\n4. ls -- view what\'s a folder in  current folder\n\n$ ')
	if x in ['mkdir', 'rm', 'rmdir', 'ls']:
		ins(x) if x in ['mkdir', 'rm', 'rmdir'] else view()
	elif  x == 'exit':
		return True
	else:
		print('Unknown Command!')
		
root = input('Enter the name of the root file: ')
users, files, done = [], [], False
while not done:
	done = main()
