// Last updated: 6/16/2026, 6:17:46 PM
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
14    bool isSymmetric(TreeNode* root) {
15        if (!root) {
16            return true;
17        }
18        // isSymmetricHelper(root->left, root->right)
19        stack<TreeNode *> nodes;
20        nodes.emplace(root->left);
21        nodes.emplace(root->right);
22
23        while (!nodes.empty())  {
24            auto right = nodes.top();
25            nodes.pop();
26            auto left = nodes.top();
27            nodes.pop();
28            if (!left && !right) {
29                continue;
30            }
31            if (!left || !right || left->val != right->val) {
32                return false;
33            }
34            // isSymmetricHelper(left->right, right->left)
35            nodes.emplace(left->right);
36            nodes.emplace(right->left);
37
38            // isSymmetricHelper(left->left, right->right)
39            nodes.emplace(left->left);
40            nodes.emplace(right->right);
41        }
42        return true;
43    }
44};
45