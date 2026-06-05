// Last updated: 6/5/2026, 8:42:05 PM
1class Solution {
2public:
3    string simplifyPath(string path) {
4        vector<string> names;
5        vector<string> tokens(move(split(path, '/')));
6        for (const auto& token : tokens) {
7            if (token == ".." && !names.empty()) {
8                names.pop_back();
9            } else if (token != ".." && token != "." && !token.empty()) {
10                names.emplace_back(token);
11            }
12        }
13        return string("/").append(join(names, '/'));
14    }
15
16private:
17    // Split string by delimitor.
18    vector<string> split(const string& s, const char delim) {
19        vector<string> tokens;
20        stringstream ss(s);
21        string token;
22        while (getline(ss, token, delim)) {
23            tokens.emplace_back(token);
24        }
25        return tokens;
26    }
27
28    // Join strings with delimitor.
29    string join(const vector<string>& names, const char delim) {
30        ostringstream ss;
31        if (!names.empty()) {
32            const string delim_str(1, delim);
33            copy(names.cbegin(), prev(names.cend()),
34                 ostream_iterator<string>(ss, delim_str.c_str()));
35            ss << names.back();
36        }
37        return ss.str();
38    }
39};