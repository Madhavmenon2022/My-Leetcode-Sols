// Last updated: 6/6/2026, 9:39:43 AM
1class Solution {
2public:
3    vector<int> grayCode(int n) {
4        vector<int> result = {0};
5        for (int i = 0; i < n; ++i) {
6            for (int j = result.size() - 1; j >= 0; --j) {
7                result.emplace_back(1 << i | result[j]);
8            }
9        }
10        return result;
11    }
12};
13