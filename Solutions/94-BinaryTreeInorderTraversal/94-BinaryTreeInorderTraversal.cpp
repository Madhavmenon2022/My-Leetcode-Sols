// Last updated: 6/16/2026, 6:07:35 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    vector<int> inorderTraversal(TreeNode* root) {
15        vector<int> res;
16        TreeNode *curr = root;
17        while (curr) {
18            if (!curr->left) {
19                res.emplace_back(curr->val);
20                curr = curr->right;
21            } else {
22                TreeNode *node = curr->left;
23                while (node->right && node->right != curr) {
24                    node = node->right;
25                }
26                if (!node->right) {
27                    node->right = curr;
28                    curr = curr->left;
29                } else {
30                    res.emplace_back(curr->val);
31                    node->right = nullptr;
32                    curr = curr->right;
33                }
34            }
35        }
36        return res;
37    }
38};
39