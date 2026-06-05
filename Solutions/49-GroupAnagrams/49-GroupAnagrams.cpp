// Last updated: 6/5/2026, 3:51:50 PM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string, vector<string>> groups;
5        for (const auto& str : strs) {
6            string tmp{str};
7            sort(tmp.begin(), tmp.end());
8            groups[tmp].emplace_back(str);
9        }
10
11        vector<vector<string>> anagrams;
12        for (const auto& kvp : groups) {
13            vector<string> group;
14            for (const auto& str : kvp.second) {
15                group.emplace_back(str);
16            }
17            sort(group.begin(), group.end());
18            anagrams.emplace_back(move(group));
19        }
20
21        return anagrams;
22    }
23};