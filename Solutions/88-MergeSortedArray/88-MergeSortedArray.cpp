// Last updated: 6/6/2026, 9:38:35 AM
1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        int i = m + n;
5        while (m > 0 && n > 0) {
6            if (nums1[m - 1] > nums2[n - 1]) {
7                nums1[i - 1] = nums1[m - 1];
8                --m;
9            } else {
10                nums1[i - 1] = nums2[n - 1];
11                --n;
12            }
13            --i;
14        }
15
16        while (n > 0) {
17            nums1[i - 1] = nums2[n - 1];
18            --n;
19            --i;
20        }
21    }
22};