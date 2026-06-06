// Last updated: 6/6/2026, 9:40:16 AM
1class Solution {
2public:
3    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
4        vector<vector<int>> result(1);
5        sort(nums.begin(), nums.end());
6        size_t previous_size = 0;
7        for (size_t i = 0; i < nums.size(); ++i) {
8            const size_t size = result.size();
9            for (size_t j = 0; j < size; ++j) {
10                // Only union non-duplicate element or new union set.
11                if (i == 0 || nums[i] != nums[i - 1] || j >= previous_size) {
12                    result.emplace_back(result[j]);
13                    result.back().emplace_back(nums[i]);
14                }
15            }
16            previous_size = size;
17        }
18        return result;
19    }
20};