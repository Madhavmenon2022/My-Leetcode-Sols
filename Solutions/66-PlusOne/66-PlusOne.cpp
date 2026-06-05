// Last updated: 6/5/2026, 8:38:04 PM
1class Solution {
2public:
3    string addBinary(string a, string b) {
4        string res;
5        size_t res_len = max(a.length(), b.length()) ;
6
7        size_t carry = 0;
8        for (int i = 0; i < res_len; ++i) {
9            const size_t a_bit_i = i < a.length() ? a[a.length() - 1 - i] - '0' : 0;
10            const size_t b_bit_i = i < b.length() ? b[b.length() - 1 - i] - '0' : 0;
11            size_t sum = carry + a_bit_i + b_bit_i;
12            carry = sum / 2;
13            sum %= 2;
14            res.push_back('0' + sum);
15        }
16        if (carry) {
17            res.push_back('0' + carry);
18        }
19        reverse(res.begin(), res.end());
20
21        return res;
22    }
23};
24