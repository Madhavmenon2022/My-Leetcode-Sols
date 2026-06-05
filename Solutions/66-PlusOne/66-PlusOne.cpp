// Last updated: 6/5/2026, 8:41:35 PM
1class Solution {
2public:
3    int climbStairs(int n) {
4        vector<int> steps(3, 0);
5        steps[0] = 1;
6        steps[1] = 1;
7        for (int i = 2; i <= n; ++i) {
8            steps[i % 3] = steps[(i - 1) % 3] + steps[(i - 2) % 3];
9        }
10        return steps[n % 3];
11    }
12};