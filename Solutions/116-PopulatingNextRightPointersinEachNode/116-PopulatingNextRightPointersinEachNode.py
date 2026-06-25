# Last updated: 6/25/2026, 6:24:09 PM
1"""
2# Definition for a Node.
3class Node(object):
4    def __init__(self, val=0, left=None, right=None, next=None):
5        self.val = val
6        self.left = left
7        self.right = right
8        self.next = next
9"""
10
11class TreeNode(object):
12    def __init__(self, x):
13        self.val = x
14        self.left = None
15        self.right = None
16        self.next = None
17
18    def __repr__(self):
19        if self is None:
20            return "Nil"
21        else:
22            return "{} -> {}".format(self.val, repr(self.next))
23
24class Solution(object):
25    # @param root, a tree node
26    # @return nothing
27    def connect(self, root):
28        if root is None:
29            return
30        if root.left:
31            root.left.next = root.right
32        if root.right and root.next:
33            root.right.next = root.next.left
34        self.connect(root.left)
35        self.connect(root.right)
36
37        return root