// Last updated: 6/6/2026, 9:34:44 AM
1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        vector<int> stk = {-1};
5        int result = 0;
6        for (int i = 0; i <= size(heights); ++i) {
7            while (stk.back() != -1 && (i == size(heights) || heights[stk.back()] >= heights[i])) {
8                int last = stk.back(); stk.pop_back();
9                result = max(result, heights[last] * ((i - 1) - stk.back()));
10            }
11            stk.emplace_back(i);
12        }
13        return result;
14    }
15};