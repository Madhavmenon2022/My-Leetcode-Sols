// Last updated: 6/5/2026, 6:12:06 PM
1class Solution {
2public:
3    /**
4     * @param n an integer
5     * @return a square matrix
6     */
7    vector<vector<int>> generateMatrix(int n) {
8       vector<vector<int>> matrix(n, vector<int>(n));
9
10       for (int num = 0, left = 0, right = n - 1, top = 0, bottom = n - 1;
11            left <= right && top <= bottom;
12            ++left, --right, ++top, --bottom) {
13
14            for (int j = left; j <= right; ++j) {
15                matrix[top][j] = ++num;
16            }
17            for (int i = top + 1; i < bottom; ++i) {
18                matrix[i][right] = ++num;
19            }
20            for (int j = right; top < bottom && j >= left; --j) {
21                matrix[bottom][j] = ++num;
22            }
23            for (int i = bottom - 1; left < right && i >= top + 1; --i) {
24                matrix[i][left] = ++num;
25            }
26        }
27
28        return matrix;
29    }
30};