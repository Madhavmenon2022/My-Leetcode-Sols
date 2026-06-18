// Last updated: 6/18/2026, 9:05:20 AM
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
14    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
15        unordered_map<int, size_t> in_entry_idx_map;
16        for (size_t i = 0; i < inorder.size(); ++i) {
17            in_entry_idx_map.emplace(inorder[i], i);
18        }
19        return ReconstructPreInOrdersHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size(),
20                                            in_entry_idx_map);
21    }
22
23    // Reconstructs the binary tree from pre[pre_s : pre_e - 1] and
24    // in[in_s : in_e - 1].
25    TreeNode *ReconstructPreInOrdersHelper(const vector<int>& preorder, size_t pre_s, size_t pre_e,
26                                           const vector<int>& inorder, size_t in_s, size_t in_e,
27                                           const unordered_map<int, size_t>& in_entry_idx_map) {
28        if (pre_s == pre_e || in_s == in_e) {
29            return nullptr;
30        }
31
32        auto idx = in_entry_idx_map.at(preorder[pre_s]);
33        auto left_tree_size = idx - in_s;
34
35        auto node = new TreeNode(preorder[pre_s]);
36        node->left = ReconstructPreInOrdersHelper(preorder, pre_s + 1, pre_s + 1 + left_tree_size,
37                                                  inorder, in_s, idx, in_entry_idx_map);
38        node->right = ReconstructPreInOrdersHelper(preorder, pre_s + 1 + left_tree_size, pre_e,
39                                                   inorder, idx + 1, in_e, in_entry_idx_map);
40        return node;
41    }
42};