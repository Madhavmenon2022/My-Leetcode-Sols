// Last updated: 6/5/2026, 6:13:52 PM
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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if (head == nullptr || head->next == nullptr) {
15            return head;
16        }
17
18        int n = 1;
19        auto curr = head;
20        for (; curr->next; curr = curr->next) {
21            ++n;
22        }
23        curr->next = head;
24
25        auto tail = curr;
26        k = n - k % n;
27        curr = head;
28        for (int i = 0; i < k; curr = curr->next, ++i) {
29            tail = curr;
30        }
31
32        tail->next = nullptr;
33        return curr; 
34    }
35};