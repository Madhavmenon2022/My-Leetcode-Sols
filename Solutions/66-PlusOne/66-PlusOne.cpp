// Last updated: 6/5/2026, 8:43:55 PM
1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        if (matrix.empty()) {
5            return;
6        }
7
8        bool has_zero = false;
9        int zero_i = -1, zero_j = -1;
10
11        for (int i = 0; i < matrix.size(); ++i) {
12            for (int j = 0; j < matrix[0].size(); ++j) {
13                if (matrix[i][j] == 0) {
14                    if (!has_zero) {
15                        zero_i = i;
16                        zero_j = j;
17                        has_zero = true;
18                    }
19                    matrix[zero_i][j] = 0;
20                    matrix[i][zero_j] = 0;
21                }
22            }
23        }
24
25        if (has_zero) {
26            for (int i = 0; i < matrix.size(); ++i) {
27                if (i == zero_i) {
28                    continue;
29                }
30                for (int j = 0; j < matrix[0].size(); ++j) {
31                    if (j == zero_j) {
32                        continue;
33                    }
34                    if (matrix[zero_i][j] == 0 || matrix[i][zero_j] == 0) {
35                        matrix[i][j] = 0;
36                    }
37                }
38            }
39            for (int i = 0; i < matrix.size(); ++i) {
40                matrix[i][zero_j] = 0;
41            }
42            for (int j = 0; j < matrix[0].size(); ++j) {
43                matrix[zero_i][j] = 0;
44            }
45        }
46    }
47};