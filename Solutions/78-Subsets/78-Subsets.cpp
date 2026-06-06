// Last updated: 6/6/2026, 9:29:56 AM
1class Solution {
2public:
3    vector<vector<int> > subsets(vector<int> &nums) {
4        vector<vector<int>> result(1);
5        sort(nums.begin(), nums.end());
6        for (size_t i = 0; i < nums.size(); ++i) {
7            const size_t size = result.size();
8            for (size_t j = 0; j < size; ++j) {
9                result.emplace_back(result[j]);
10                result.back().emplace_back(nums[i]);
11            }
12        }
13        return result;
14    }
15};