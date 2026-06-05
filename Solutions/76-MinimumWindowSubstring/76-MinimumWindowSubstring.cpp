// Last updated: 6/5/2026, 8:48:50 PM
1class Solution {
2public:
3    string minWindow(string s, string t) {
4        unordered_map<int, int> count;
5        for (const auto& c : t) {
6            ++count[c];
7        }
8        int remain = t.length();
9        int left = -1, right = -1;
10        for (int i = 0, j = 0; j < s.length(); ++j) {
11            remain -= count[s[j]]-- > 0;
12            if (remain) {
13                continue;
14            }
15            while (count[s[i]] < 0) {
16                ++count[s[i++]];
17            }
18            if (right == -1 || j - i + 1 < right - left + 1) {
19                left = i;
20                right = j;
21            }
22        }
23        return left >= 0 ? s.substr(left, right - left + 1) : "";
24    }
25};
26