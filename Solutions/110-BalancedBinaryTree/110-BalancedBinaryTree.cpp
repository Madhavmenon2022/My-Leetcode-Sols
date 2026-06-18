// Last updated: 6/18/2026, 9:01:21 AM
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
14    int diameterOfBinaryTree(TreeNode* root) {
15        return iter_dfs(root);
16    }
17
18private:
19    int iter_dfs(TreeNode *node) {
20        int result = 0;
21 
22        vector<function<void()>> stk;
23        function<void(TreeNode*, int*)> divide;
24        function<void(TreeNode*, shared_ptr<int>&, shared_ptr<int>&, int *)> conquer;
25        divide = [&](TreeNode *node, int *ret) {
26            if (!node) {
27                return;
28            }
29            auto ret1 = make_shared<int>(), ret2 = make_shared<int>();
30            stk.emplace_back(bind(conquer, node, ret1, ret2, ret));
31            stk.emplace_back(bind(divide, node->right, ret2.get()));
32            stk.emplace_back(bind(divide, node->left, ret1.get()));
33        };
34        conquer = [&](TreeNode *node, shared_ptr<int> ret1, shared_ptr<int> ret2, int *ret) {
35            result = max(result, *ret1 + *ret2);
36            *ret = 1 + max(*ret1, *ret2);
37        };
38
39        int max_h = 0;
40        stk.emplace_back(bind(divide, node, &max_h));
41        while (!stk.empty()) {
42            auto cb = move(stk.back()); stk.pop_back();
43            cb();
44        }
45        return result;
46    }
47};