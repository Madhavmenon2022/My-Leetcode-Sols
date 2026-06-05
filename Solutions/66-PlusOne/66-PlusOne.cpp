// Last updated: 6/5/2026, 8:38:50 PM
1class Solution {
2public:
3    vector<string> fullJustify(vector<string>& words, int maxWidth) {
4        vector<string> res;
5        const int n = words.size();
6        int begin = 0, len = 0;
7        for (int i = 0; i < n; ++i) {
8            if (len + words[i].size() + (i - begin) > maxWidth) {
9                res.emplace_back(connect(words, maxWidth, begin, i, len, false));
10                begin = i;
11                len = 0;
12            }
13            len += words[i].size();
14        }
15        // Last line.
16        res.emplace_back(connect(words, maxWidth, begin, n, len, true));
17        return res;
18    }
19
20private:
21    string connect(const vector<string>& words, int maxWidth,
22                   int begin, int end, int len,
23                   bool is_last) {
24        string s;
25        int n = end - begin;
26        for (int i = 0; i < n; ++i) {
27            s += words[begin + i];
28            addSpaces(i, n - 1, maxWidth - len, is_last, &s);
29        }
30        // For only one word in a line.
31        if (s.size() < maxWidth) {
32            s.append(maxWidth - s.size(), ' ');
33        }
34        return s;
35    }
36
37    void addSpaces(int i, int spaceCnt, int maxWidth, bool is_last, string *s) {
38        if (i < spaceCnt) {
39            // For the last line of text, it should be left justified,
40            // and no extra space is inserted between words.
41            int spaces = is_last ? 1 : maxWidth / spaceCnt + (i < maxWidth % spaceCnt);
42            s->append(spaces, ' ');
43        }
44    }
45};