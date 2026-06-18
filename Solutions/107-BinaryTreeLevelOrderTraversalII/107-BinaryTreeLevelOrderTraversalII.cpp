// Last updated: 6/18/2026, 9:07:11 AM
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
14    vector<vector<int>> levelOrderBottom(TreeNode* root) {
15        vector<vector<int>> result;
16        queue<TreeNode *> que;
17
18        if (root != nullptr) {
19            que.emplace(root);
20        }
21
22        while (!que.empty()) {
23            vector<int> level;
24            int size = que.size();
25            for (int i = 0; i < size; i++) {
26                auto *front = que.front();
27                que.pop();
28                level.emplace_back(front->val);
29                if (front->left != nullptr) {
30                    que.emplace(front->left);
31                }
32                if (front->right != nullptr) {
33                    que.emplace(front->right);
34                }
35            }
36            result.emplace_back(move(level));
37        }
38        
39        // The only difference between binary-tree-level-order-traversal
40        // and binary-tree-level-order-traversal-ii
41        reverse(result.begin(), result.end());
42        
43        return result;
44    }
45};