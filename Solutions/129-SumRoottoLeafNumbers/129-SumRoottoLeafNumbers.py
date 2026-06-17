# Last updated: 6/17/2026, 10:06:20 AM
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
16    def sumNumbers(self, root):
17        return self.sumNumbersRecu(root, 0)
18
19    def sumNumbersRecu(self, root, num):
20        if root is None:
21            return 0
22
23        if root.left is None and root.right is None:
24            return num * 10 + root.val
25
26        return self.sumNumbersRecu(root.left, num * 10 + root.val) + self.sumNumbersRecu(root.right, num * 10 + root.val)