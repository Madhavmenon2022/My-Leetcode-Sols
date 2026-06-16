// Last updated: 6/16/2026, 6:08:31 PM
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
14    vector<TreeNode*> generateTrees(int n) {
15        if (n == 0) {
16            return {};
17        }
18        return generateTreesHelper(1, n);
19    }
20
21private:
22    vector<TreeNode *> generateTreesHelper(int start, int end) {
23        vector<TreeNode *> result;
24        if (start > end) {
25            result.emplace_back(nullptr);
26            return result;
27        }
28
29        for (int i = start; i <= end; ++i) {
30            vector<TreeNode *> leftSubTrees = generateTreesHelper(start, i - 1);
31            vector<TreeNode *> rightSubTrees = generateTreesHelper(i + 1, end);
32            for (const auto& left : leftSubTrees) {
33                for (const auto& right : rightSubTrees) {
34                    TreeNode *root = new TreeNode(i);
35                    root->left = clone(left);
36                    root->right = clone(right);
37                    result.emplace_back(root);
38                }
39            }
40
41        }
42        return result;
43    }
44
45    TreeNode *clone(TreeNode *root) {
46        TreeNode *newRoot = nullptr;
47
48        if (root) {
49            newRoot = new TreeNode(root->val);
50            newRoot->left = clone(root->left);
51            newRoot->right = clone(root->right);
52        }
53
54        return newRoot;
55    }
56};