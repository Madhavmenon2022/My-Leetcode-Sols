# Last updated: 6/25/2026, 6:20:15 PM
1# Definition for a binary tree node.
2# class TreeNode(object):
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class TreeNode(object):
8    def __init__(self, x):
9        self.val = x
10        self.left = None
11        self.right = None
12
13class Solution(object):
14    # @param root, a tree node
15    # @return nothing, do it in place
16    def flatten(self, root):
17        self.flattenRecu(root, None)
18
19    def flattenRecu(self, root, list_head):
20        if root:
21            list_head = self.flattenRecu(root.right, list_head)
22            list_head = self.flattenRecu(root.left, list_head)
23            root.right = list_head
24            root.left = None
25            return root
26        else:
27            return list_head