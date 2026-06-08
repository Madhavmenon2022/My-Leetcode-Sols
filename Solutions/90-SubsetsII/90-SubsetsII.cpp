// Last updated: 6/8/2026, 2:43:52 PM
1class Solution {
2public:
3    int numDecodings(string s) {
4        if (s.empty()) {
5            return 0;
6        }
7
8        int prev = 0; // f[n - 2]
9        int cur = 1;  // f[n - 1]
10
11        for (int i = 0; i < s.length(); ++i) {
12            if (s[i] == '0') {
13                cur = 0; // f[n - 1] = 0
14            }
15            if (i == 0 ||
16                !(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
17                prev = 0; // f[n - 2] = 0
18            }
19
20            int tmp = cur;
21            cur += prev; // f[n] = f[n - 1] + f[n - 2]
22            prev = tmp;
23        }
24
25        return cur;
26    }
27};