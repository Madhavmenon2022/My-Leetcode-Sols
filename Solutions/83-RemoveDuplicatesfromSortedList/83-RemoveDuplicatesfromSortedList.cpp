// Last updated: 6/6/2026, 9:34:08 AM
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
11class Solution {
12public:
13    ListNode* deleteDuplicates(ListNode* head) {
14        auto iter = head;
15        while (iter) {
16            auto runner = iter->next;
17            while (runner && runner->val == iter->val) {
18                runner = runner->next;
19            }
20            iter->next = runner;
21            iter = runner;
22        }
23        return head; 
24    }
25};