// Last updated: 6/6/2026, 9:33:18 AM
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
14        ListNode dummy{0};
15        auto prev = &dummy;
16        while (head) {
17            if (head->next && head->next->val == head->val) {
18                auto val = head->val;
19                while (head && head->val == val) {
20                    head = head->next;
21                }
22                prev->next = head;
23            } else {
24                prev->next = head;
25                prev = head;
26                head = head->next;
27            }
28        }
29        return dummy.next;
30    }
31};