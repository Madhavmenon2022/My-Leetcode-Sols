// Last updated: 6/5/2026, 3:57:00 PM
1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int result = numeric_limits<int>::min();
5        int curr = numeric_limits<int>::min();
6        for (const auto &x : nums) {
7            curr = (curr == numeric_limits<int>::min()) ? x : max(curr + x, x);
8            result = max(result, curr);
9        }
10        return result;
11    }
12};