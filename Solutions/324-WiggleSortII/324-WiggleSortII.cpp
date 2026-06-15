// Last updated: 6/15/2026, 8:18:03 AM
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
13    ListNode* reverseBetween(ListNode* head, int m, int n) {
14        ListNode dummy{0};
15        dummy.next = head;
16
17        auto *prev = &dummy;
18
19        for (int i = 0; i < m - 1; ++i) {
20            prev = prev->next;
21        }
22
23        auto *head2 = prev;
24
25        prev = prev->next;
26        auto *cur = prev->next;
27
28        for (int i = m; i < n; ++i) {
29            prev->next = cur->next;  // Remove cur from the list.
30            cur->next = head2->next; // Add cur to the head.
31            head2->next = cur;       // Add cur to the head.
32            cur = prev->next;        // Get next cur.
33        }
34
35        return dummy.next;
36    }
37};