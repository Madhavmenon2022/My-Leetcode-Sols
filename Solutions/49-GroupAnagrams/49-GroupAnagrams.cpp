// Last updated: 6/5/2026, 3:58:15 PM
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        vector<int> res;
5        if (matrix.empty()) {
6            return res;
7        }
8
9        for (int left = 0, right = matrix[0].size() - 1,
10                 top = 0, bottom = matrix.size() - 1;
11             left <= right && top <= bottom;
12             ++left, --right, ++top, --bottom) {
13
14            for (int j = left; j <= right; ++j) {
15                res.emplace_back(matrix[top][j]);
16            }
17            for (int i = top + 1; i < bottom; ++i) {
18                res.emplace_back(matrix[i][right]);
19            }
20            for (int j = right; top < bottom && j >= left; --j) {
21                res.emplace_back(matrix[bottom][j]);
22            }
23            for (int i = bottom - 1; left < right && i > top; --i) {
24                res.emplace_back(matrix[i][left]);
25            }
26        }
27
28        return res;
29    }
30};