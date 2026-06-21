// Last updated: 6/21/2026, 8:18:13 PM
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
14    TreeNode* sortedArrayToBST(vector<int>& nums) {
15        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
16    }
17
18private:
19    TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int start, int end) {
20        if (start <= end) {
21            TreeNode *node = new TreeNode(nums[start + (end - start) / 2]);
22            node->left = sortedArrayToBSTHelper(nums, start, start + (end - start) / 2 - 1);
23            node->right = sortedArrayToBSTHelper(nums, start + (end - start) / 2 + 1, end);
24            return node;
25        }
26        return nullptr;
27    }
28};