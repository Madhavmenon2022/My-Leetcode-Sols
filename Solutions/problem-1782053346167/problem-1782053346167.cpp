// Last updated: 6/21/2026, 8:19:06 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11/**
12 * Definition for a binary tree node.
13 * struct TreeNode {
14 *     int val;
15 *     TreeNode *left;
16 *     TreeNode *right;
17 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
18 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
19 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
20 * };
21 */
22class Solution {
23public:
24    TreeNode* sortedListToBST(ListNode* head) {
25        auto curr = head;
26        int n = 0;
27        while (curr) {
28            curr = curr->next;
29            ++n;
30        }
31        return BuildBSTFromSortedDoublyListHelper(&head, 0, n);
32    }
33
34    TreeNode * BuildBSTFromSortedDoublyListHelper(ListNode **head, int s, int e) {
35        if (s == e) {
36            return nullptr;
37        }
38
39        int m = s + ((e - s) / 2);
40        auto left = BuildBSTFromSortedDoublyListHelper(head, s, m);
41        auto curr = new TreeNode((*head)->val);
42
43        *head = (*head)->next;
44        curr->left = left;
45        curr->right = BuildBSTFromSortedDoublyListHelper(head, m + 1, e);
46        return curr;
47    }
48};