# Last updated: 6/25/2026, 6:19:00 PM
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
15    # @param sum, an integer
16    # @return a boolean
17    def hasPathSum(self, root, sum):
18        if root is None:
19            return False
20
21        if root.left is None and root.right is None and root.val == sum:
22            return True
23
24        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)