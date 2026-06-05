// Last updated: 6/5/2026, 4:05:32 PM
1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
4        size_t i = 0;
5        vector<vector<int>> result;
6        // Insert intervals appeared before newInterval.
7        while (i < size(intervals) && newInterval[0] > intervals[i][1]) {
8            result.emplace_back(intervals[i++]);
9        }
10
11        // Merge intervals that overlap with newInterval.
12        while (i < size(intervals) && newInterval[1] >= intervals[i][0]) {
13            newInterval = {min(newInterval[0], intervals[i][0]),
14                           max(newInterval[1], intervals[i][1])};
15            ++i;
16        }
17        result.emplace_back(newInterval);
18
19        // Insert intervals appearing after newInterval.
20        copy(cbegin(intervals) + i, cend(intervals), back_inserter(result));
21        return result;
22    }
23};