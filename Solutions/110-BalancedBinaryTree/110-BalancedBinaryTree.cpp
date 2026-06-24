// Last updated: 6/24/2026, 9:17:11 AM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
4        const int g = accumulate(cbegin(numsDivide), cend(numsDivide), numsDivide[0],
5                                 [](const auto& total, const auto& x) {
6                                     return gcd(total, x);
7                                 });
8        int mn = numeric_limits<int>::max();
9        for (const auto& x : nums) {
10            if (g % x == 0) {
11                mn = min(mn, x);
12            }
13        }
14        return mn != numeric_limits<int>::max() ? accumulate(cbegin(nums), cend(nums), 0,
15                                                             [&](const auto& total, const auto& x) {
16                                                                 return total + static_cast<int>(x < mn);
17                                                             }): -1;
18    }
19};