// Last updated: 6/5/2026, 8:39:58 PM
1class Solution {
2public:
3    int mySqrt(int x) {
4        if (x < 2) {
5            return x;
6        }
7        
8        int left = 1, right = x / 2;
9        while (left <= right) {
10            const auto mid = left + (right - left) / 2;
11            if (mid > x / mid) {
12                right = mid - 1;
13            } else {
14                left = mid + 1;
15            }
16        }
17
18        return left - 1;
19    }
20};