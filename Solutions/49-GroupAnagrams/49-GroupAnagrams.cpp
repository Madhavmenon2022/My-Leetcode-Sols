// Last updated: 6/5/2026, 3:53:04 PM
1class Solution {
2public:
3    double myPow(double x, int n) {
4        double result = 1;
5        long long abs_n = abs(static_cast<long long>(n));
6        while (abs_n > 0) {
7            if (abs_n & 1) {
8                result *= x;
9            }
10            abs_n >>= 1;
11            x *= x;
12        }
13        return n < 0 ? 1 / result : result;
14    }
15};