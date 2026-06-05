// Last updated: 6/5/2026, 6:18:32 PM
1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        for (int i = digits.size() - 1; i >= 0; --i) {
5            if (digits[i] == 9) {
6                digits[i] = 0;
7            } else {
8                ++digits[i];
9                return digits;
10            }
11        }
12        digits[0] = 1;
13        digits.emplace_back(0);
14        return digits;
15    }
16};