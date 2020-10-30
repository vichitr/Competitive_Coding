# Python3 program to print cousins of a node 

# A utility function to create a new 
# Binary Tree Node 
class newNode: 
	def __init__(self, item): 
		self.data = item 
		self.left = self.right = None

# It returns level of the node if it is 
# present in tree, otherwise returns 0. 
def getLevel(root, node, level): 
	
	# base cases 
	if (root == None): 
		return 0
	if (root == node): 
		return level 

	# If node is present in left subtree 
	downlevel = getLevel(root.left, node, 
							level + 1) 
	if (downlevel != 0): 
		return downlevel 

	# If node is not present in left subtree 
	return getLevel(root.right, node, level + 1) 

# Prnodes at a given level such that 
# sibling of node is not printed if 
# it exists 
def printGivenLevel(root, node, level): 
	
	# Base cases 
	if (root == None or level < 2): 
		return

	# If current node is parent of a 
	# node with given level 
	if (level == 2): 
		if (root.left == node or
			root.right == node): 
			return
		if (root.left): 
			print(root.left.data, end = " ") 
		if (root.right): 
			print(root.right.data, end = " ") 

	# Recur for left and right subtrees 
	elif (level > 2): 
		printGivenLevel(root.left, node, level - 1) 
		printGivenLevel(root.right, node, level - 1) 

# This function prints cousins of a given node 
def printCousins(root, node): 
	
	# Get level of given node 
	level = getLevel(root, node, 1) 

	# Prnodes of given level. 
	printGivenLevel(root, node, level) 

# Driver Code 
if __name__ == '__main__': 
	root = newNode(11) 
	root.left = newNode(20) 
	root.right = newNode(31) 
	root.left.left = newNode(-4) 
	root.left.right = newNode(5) 
	root.left.right.right = newNode(15) 
	root.right.left = newNode(76) 
	root.right.right = newNode(77) 
	root.right.left.right = newNode(18) 

	printCousins(root, root.left.right)  
