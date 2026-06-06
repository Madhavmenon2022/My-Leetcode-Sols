// Last updated: 6/6/2026, 9:36:21 AM
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
13    ListNode *partition(ListNode *head, int x) {
14        ListNode dummy_smaller{0};
15        ListNode dummy_larger{0};
16        auto smaller = &dummy_smaller;
17        auto larger = &dummy_larger;
18
19        while (head) {
20            if (head->val < x) {
21                smaller->next = head;
22                smaller = smaller->next;
23            } else {
24                larger->next = head;
25                larger = larger->next;
26            }
27            head = head->next;
28        }
29        smaller->next = dummy_larger.next;
30        larger->next = nullptr;
31
32        return dummy_smaller.next;
33    }
34};