// Last updated: 6/5/2026, 6:11:23 PM
1class Solution {
2public:
3    int lengthOfLastWord(string s) {
4        const auto is_space = [](const char c) { return isspace(c); };
5        const auto it = find_if_not(s.rbegin(), s.rend(), is_space);
6        const auto jt = find_if(it, s.rend(), is_space);
7        return distance(it, jt);
8    }
9};