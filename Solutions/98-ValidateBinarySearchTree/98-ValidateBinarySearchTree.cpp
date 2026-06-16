// Last updated: 6/16/2026, 6:13:06 PM
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
14    bool isValidBST(TreeNode* root) {
15        if (!root) {
16            return true;
17        }
18
19        if (!isValidBST(root->left)) {
20            return false;
21        }
22
23        if (last && last != root && last->val >= root->val) {
24            return false;
25        }
26
27        last = root;
28
29        if (!isValidBST(root->right)) {
30            return false;
31        }
32
33        return true;
34    }
35
36private:
37    TreeNode *last = nullptr;
38};