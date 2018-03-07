import TreeModule

# Create some trees using the function in TreeModule
t1 = TreeModule.tree_factory("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
t2 = TreeModule.tree_factory(("1","2","3","4","5","6","7","8","9","10","11"))

trees = (t1,t2)

# pretty print a collection of trees
def prettyPrint(trees):
    i=0
    for t in trees:
        i += 1
        print ("Tree:", i)
        TreeModule.print_tree_indented(t)
        print

# To test functions in this module (from the edit window):
# select the  "Run" pull down menu,  thne choose "Run Module"

# Note: TreeModule will be imported.  You can access its definition
#           by prefixing functions and class name with "TreeModule", i.e.

# >>> tr= TreeModule.tree_factory([1,2,3,4])
# >>> tr
# 3 2 1 4
# >>> tr2 = tree_factory([4,5,6,7])
# Traceback (most recent call last):
#  File "<pyshell#4>", line 1, in -toplevel-
#    tr2 = tree_factory([4,5,6,7])
# NameError: name 'tree_factory' is not defined

##########################################################
# Define a function treeGenerator that generate all possible trees with n nodes.
# Use python generators as part of your solution.  Note that CLU iterators are
# what python calls generators.
# See section 2.2 of Advanced Programming Language Design
#     for example in CLU
# http://www.nondot.org/sabre/Mirrored/AdvProgLangDesign/finkel00.pdf
# or ftp://ftp.aw.com/cseng/authors/finkel/apld/
# e.g.  trees are all possible trees with 3 nodes.


# >>> trees = treeGenerator(1,3)
# >>> prettyPrint(trees)
#Tree: 1
#    2
#  1
#0
#
#Tree: 2
#  1
#    2
#0

#Tree: 3
#  1
#0
#  1

#Tree: 4
#0
#    2
#  1

#Tree: 5
#0
#  1
#    2

def treeGenerator(start,end):
    treeList = []
    if start <= end: #if we arent at maximum depth
        for root in range(start,end+1):
            curTree = TreeModule.Tree(root, None,None) #we create, in an inorder fashion, our tree possiblities recursively.
            leftList = treeGenerator(start,root-1) #go left , go back to the previous line, and make a new parent, and continue the process until we have made a treee that goes entirely left.
            rightList = treeGenerator(root+1,end)
            for leftTree in leftList:
                curTree.left = leftTree
                for rightTree in rightList:
                    curTree.right = rightTree
                    treeList.append(curTree)
    else: #at max depth so no more recursion, just leefs
        treeList.append(None)

    yield treeList

trees = treeGenerator(1,3)
prettyPrint(trees)
