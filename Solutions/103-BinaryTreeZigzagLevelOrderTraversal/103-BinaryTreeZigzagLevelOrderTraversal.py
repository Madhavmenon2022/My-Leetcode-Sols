# Last updated: 6/16/2026, 6:20:19 PM
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
16    # @return a list of lists of integers
17    def zigzagLevelOrder(self, root):
18        if root is None:
19            return []
20        result, current = [], [root]
21        while current:
22            next_level, vals = [], []
23            for node in current:
24                vals.append(node.val)
25                if node.left:
26                    next_level.append(node.left)
27                if node.right:
28                    next_level.append(node.right)
29            result.append(vals[::-1] if len(result) % 2 else vals)
30            current = next_level
31        return result