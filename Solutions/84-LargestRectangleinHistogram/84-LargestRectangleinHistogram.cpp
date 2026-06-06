// Last updated: 6/6/2026, 9:35:44 AM
1class Solution {
2public:
3    int maximalRectangle(vector<vector<char> > &matrix) {
4        if (matrix.empty() || matrix[0].empty()) {
5            return 0;
6        }
7
8        int result = 0;
9        vector<int> heights(matrix[0].size(), 0);
10        for (int i = 0; i < matrix.size(); ++i) {
11            for (int j = 0; j < matrix[0].size(); ++j) {
12                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
13            }
14            result = max(result, largestRectangleArea(heights));
15        }
16        return result;
17    }
18
19private:
20    int largestRectangleArea(const vector<int>& heights) {
21        vector<int> stk = {-1};
22        int res = 0;
23        for (int i = 0; i <= size(heights); ++i) {
24            while (stk.back() != -1 && (i == size(heights) || heights[stk.back()] >= heights[i])) {
25                int last = stk.back(); stk.pop_back();
26                res = max(res, heights[last] * ((i - 1) - stk.back()));
27            }
28            stk.emplace_back(i);
29        }
30        return res;
31    }
32};