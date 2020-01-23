# pip3 install --user anytree
from anytree import Node, RenderTree

def view():
	lst = []
	root = Node(folder)
	[lst.append(Node(i, parent=root)) for i in files]
	for pre, fill, node in RenderTree(root):
		print(str(pre)+str(node.name))

def rem(x):
	global files, folder
	if x == 'rmdir' and folder:
		folder = ''
		files=[]
		print ('Root folder removed!')
		return
	elif not folder:
		return
	rmfil = input("Enter a filename: ")
	print('None found!') if not files or rmfil not in files else files.remove(rmfil)
	view()


def ins(x):
    global folder, files
    if x in ['rm', 'rmdir']:
        rem(x)
        return
    elif folder:
        y = input('\nRoot folder will be replaced!\nContinue (*/N)? : ')
        if y in ['N', 'n']: return
    folder = input("Enter a root folder name: ")
    files = list(map(str, input("Enter the files: ").split()))
    view()

def main():
	print("\n###File Organization Commands###")
	x = input('1. mkdir -- make a directory\n2. rm -- remove a file\n3. rmdir -- removes root folder\n4. ls -- view what\'s a folder in  current folder\n\n$ ')
	if x in ['mkdir', 'rm', 'rmdir', 'ls']:
		ins(x) if x in ['mkdir', 'rm', 'rmdir'] else view()
	elif  x == 'exit':
		return True
	else:
		print('Unknown Command!')

folder, files, done = '', [], False
while not done:
	done = main()
