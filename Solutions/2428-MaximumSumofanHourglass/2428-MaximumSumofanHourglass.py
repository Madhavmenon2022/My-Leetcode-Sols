# Last updated: 6/25/2026, 6:17:42 PM
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
15    # @return an integer
16    def minDepth(self, root):
17        if root is None:
18            return 0
19
20        if root.left and root.right:
21            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
22        else:
23            return max(self.minDepth(root.left), self.minDepth(root.right)) + 1