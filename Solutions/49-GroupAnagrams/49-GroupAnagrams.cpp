// Last updated: 6/5/2026, 4:03:45 PM
1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        sort(begin(intervals), end(intervals));
5        vector<vector<int>> result;
6        for (const auto& interval : intervals) {
7            if (empty(result) || interval[0] > result.back()[1]) { 
8                result.emplace_back(interval);
9            } else {
10                result.back()[1] = max(result.back()[1], interval[1]);
11            }
12        }
13        return result;
14    }
15};