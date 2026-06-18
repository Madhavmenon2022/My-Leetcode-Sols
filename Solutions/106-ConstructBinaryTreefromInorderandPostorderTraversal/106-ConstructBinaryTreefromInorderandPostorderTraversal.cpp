// Last updated: 6/18/2026, 9:06:06 AM
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
14    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
15        unordered_map<int, size_t> in_entry_idx_map;
16        for (size_t i = 0; i < inorder.size(); ++i) {
17            in_entry_idx_map.emplace(inorder[i], i);
18        }
19        return ReconstructPostInOrdersHelper(postorder, 0, postorder.size(), inorder, 0, inorder.size(),
20                                             in_entry_idx_map);
21    }
22
23    TreeNode * ReconstructPostInOrdersHelper(const vector<int>& postorder, size_t post_s, size_t post_e,
24                                             const vector<int>& inorder, size_t in_s, size_t in_e,
25                                             const unordered_map<int, size_t>& in_entry_idx_map) {
26        if (post_s == post_e || in_s == in_e) {
27            return nullptr;
28        }
29        
30        auto idx = in_entry_idx_map.at(postorder[post_e - 1]);
31        auto left_tree_size = idx - in_s;
32
33        TreeNode *node = new TreeNode(postorder[post_e - 1]);
34        // Recursively builds the left subtree.
35        node->left =ReconstructPostInOrdersHelper(postorder, post_s, post_s + left_tree_size,
36                                                  inorder, in_s, idx, in_entry_idx_map);
37        // Recursively builds the right subtree.
38        node->right = ReconstructPostInOrdersHelper(postorder, post_s + left_tree_size, post_e - 1,
39                                                    inorder, idx + 1, in_e, in_entry_idx_map);
40        return node;
41    }
42};