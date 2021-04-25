# Internation Collegiate Programming Contest
# November 18, 2000
# PROBLEM 2: Led Codes

# SAMPLE_INPUT = "3\nHELL1235670WO1234591561580\nPROGRAMMING037124670C123567123567156\n" \
#                "AND MORE037124903735790278134573712467045612356735792781245612467278"

# to track memory usage
from guppy import hpy
hp = hpy()
hp.setrelheap()

import psutil, os

# to calculate runtime
from time import time
before = time()

# definition of a n-ary tree
class TreeNode:

    def __init__(self, root):
        self.root = root
        self.nodes = {}     # save nodes in a dictionary

    # used to insert a new node manually
    def insertNode(self, node) -> object:
        new_node = TreeNode(node)
        self.nodes[node] = new_node

        return new_node

    # used to automaticaly insert a whole path given by a list
    def insertNodes(self, path: list):
        if path:
            value = path[0]
            if value in self.nodes:
                self.nodes[value].insertNodes(path[1:])
            else:
                new_node = TreeNode(value)
                new_node.insertNodes(path[1:])
                self.nodes[value] = new_node

    # search value by path
    def search(self, path: list):
        if path:
            next = path[0]
            if next in self.nodes:
                return self.nodes[next].search(path[1:])    # if the path continues, continue to search
            else:
                return None                                 # if the path continues, but the tree doesn't have the next
                                                            # node, return None

        child_node = list(self.nodes.items())   # if the path is finished, check if the current node is a letter or
        if not child_node[0][0].isnumeric():    # space, and returns it if true. Else, return None
            return child_node[0][0]

    # print a string visualization instead of memory address
    def __str__(self):
        output = str(self.root) + ", ("

        for node in self.nodes.values():
            output += str(node)

        output += ")"

        return output


# get paths to letters
with open("paths.txt") as file:
    lines = file.readlines()

# initialize trees
trees = {}
for line in lines:
    line = line.strip("\n")
    root = line[0]
    if root not in trees:
        trees[root] = TreeNode(root)

    path = list(line[1:])
    trees[root].insertNodes(path)

# print trees to check if everything is fine
# for tree in trees.values():
#     print(tree)


# finally, the solution :D

# get data from input file
with open("input.txt") as file:
    lines = file.readlines()[1:]    # ignore the first line, it's not necessary in python

# open output file in append mode
with open("output.txt", mode="a") as file:
    count = 1   # line counter

    # main loop to manipulate each line
    for line in lines:
        output = ""     # initialize empty string to save decoded characters
        char_list = []  # characters being checked (got the idea from Lucas' solution)
        i = 0

        # loop to scan the line for matches
        while i < len(line):
            char_list.append(line[i])
            tree = trees.get(char_list[0])  # checks if there's a tree whose root is the first char of the list
            if tree:
                letter = tree.search(char_list[1:])     # if so, searches the tree
                if letter:
                    output += letter    # if there's a match, appends the output string with the decoded letter
                    char_list = []      # clears char_list
            else:
                output += char_list[0]  # if the char isn't the root of a tree, it means it is already a decoded letter
                                        # or a space, so it just appends it to the output string
                char_list = []          # clears char_list

            i += 1

        output = output.replace("_", " ")   # i couldn't use a space as a tree node,
                                            # so i used an underscore then replaced it

        file.write(f"Phrase {count}: " + output)    # appends decoded string to the end of file
        count += 1


after = time()
print(after - before)   # print runtime

# print memory usage
h = hp.heap()
print(h)

# print memory usage
process = psutil.Process(os.getpid())
print('Used memory (in bytes): ' + str(process.memory_info().rss))