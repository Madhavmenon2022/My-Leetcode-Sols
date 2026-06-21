# Last updated: 6/21/2026, 8:20:02 PM
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
13
14class Solution(object):
15    # @param root, a tree node
16    # @return a boolean
17    def isBalanced(self, root):
18        def getHeight(root):
19            if root is None:
20                return 0
21            left_height, right_height = \
22                getHeight(root.left), getHeight(root.right)
23            if left_height < 0 or right_height < 0 or \
24               abs(left_height - right_height) > 1:
25                return -1
26            return max(left_height, right_height) + 1
27        return (getHeight(root) >= 0)