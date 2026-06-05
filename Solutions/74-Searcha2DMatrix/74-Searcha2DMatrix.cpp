// Last updated: 6/5/2026, 8:45:27 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        if (matrix.empty()) {
5            return false;
6        }
7
8        // Treat matrix as 1D array.
9        const int m = matrix.size();
10        const int n = matrix[0].size();
11        int left = 0;
12        int right = m * n - 1;
13
14        // Find min of left s.t.  matrix[left / n][left % n] >= target
15        while (left <= right) {
16            int mid = left + (right - left) / 2;
17            if (matrix[mid / n][mid % n] >= target) {
18                right = mid - 1;
19            } else {
20                left = mid + 1;
21            }
22        }
23
24        // Check if matrix[left / n][left % n] equals to target.
25        if (left != m * n && matrix[left / n][left % n] == target) {
26            return true;
27        }
28
29        return false;
30    }
31};