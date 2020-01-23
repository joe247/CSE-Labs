'''
from anytree importNode, RenderTree, AsciiStyle, PreOrderIter

f = Node("f")
b = Node("b", parent=f)
a = Node("a", parent=b)
d = Node("d", parent=b)
c = Node("c", parent=d)
e = Node("e", parent=d)
g = Node("g", parent=f)
i = Node("i", parent=g)
h = Node("h", parent=i)
print(RenderTree(f, style=AsciiStyle()).by_attr())
'''
#pip3 install --user anytree
from anytree import Node, RenderTree

files, folders = [], []
root = Node(input('Enter root file name: '))
users = list(map(str, input('Enter the users\' name: ').split()))
[files.append(list(map(str, input('Enter the files for user '+i+' : ').split()))) for i in users]
print()
[folders.append(list(map(str, input('Enter the folders for user '+i+' : ').split()))) for i in users]
print()

files1, folders1 = [], []
[files1.append(list(map(str, input('Enter the files for user '+i+'\'s folder '+str(j)+' : ').split()))) for i, k in zip(users, range(len(folders))) for j in folders[k]]
print()
[folders1.append(list(map(str, input('Enter the folders for user '+i+'\'s folder '+str(j)+' : ').split()))) for i, k in zip(users, range(len(folders))) for j in folders[k]]
print()

lvl1, lvl1f, lvl2, lvl2f, us = [], [], [], [], []
rt = Node(root, parent=None)
[us.append(Node(i, parent=root)) for i in users]
[lvl1.append(Node(j, parent=i)) for i, k in zip(us, range(len(files))) for j in files[k]]
[lvl1f.append(Node(j, parent=i)) for i, k in zip(us, range(len(folders))) for j in folders[k]]

[lvl2.append(Node(j, parent=i)) for i, k in zip(lvl1f, range(len(files1))) for j in files1[k]]
[lvl2f.append(Node(j, parent=i)) for i, k in zip(lvl1f, range(len(folders1))) for j in folders1[k]]

[print(str(pre)+str(node.name)) for pre, fill, node in RenderTree(root)]
