from util import *
from degrees import *

node = Node(state=102, parent=None, action=None)
node = Node(state=158, parent=node, action=112384)
node = Node(state=398, parent=node, action=109830)

# print(person_id_in_path(node, 103))

print(compile_path(node))

"""
Brainstorming

step by step
1) Add first connections to the frontier, based on Kevin Bacon
2) Pop one person node off of the frontier/Queue
3) Are they the Target?
  if yes: you're done, so compile and return particular node's path as output
  if no: use current node to push new nodes onto the frontier, with 2 considerations
    I) The new people to search are not already in the path
    II) They are one step away
4) Repeat steps 2 and 3
"""