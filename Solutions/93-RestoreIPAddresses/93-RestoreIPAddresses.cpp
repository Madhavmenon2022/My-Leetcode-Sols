// Last updated: 6/15/2026, 8:19:00 AM
1class Solution {
2    public:
3        vector<string> restoreIpAddresses(string s) {
4            vector<string> ans;
5            dfs(s, 0, 4, "", ans);
6            return ans;
7        }
8
9    private:
10        void dfs(const string &s, int start, int step, string ip, vector<string> &ans) {
11            if(start == s.size() && step == 0) {
12                ip.pop_back();
13                ans.push_back(ip);
14                return;
15            }
16
17            if(s.size() - start < step || s.size() - start > step * 3) // pruing
18                return;
19
20            int num = 0;
21            for(int i = start; i < start + 3; ++i) {
22                num = num * 10 + s[i] - '0';
23                if(num > 255) break;
24                ip += s[i];
25                dfs(s, i + 1, step - 1, ip + '.', ans);
26                if(num == 0) break; // only one 0
27            }
28        }
29};