// Last updated: 6/5/2026, 6:14:29 PM
1class Solution {
2    public:
3        unordered_map<int, unordered_map<int, int> > hash;
4        int uniquePaths(int m, int n) {
5            if(m == 0 || n == 0)
6                return 0;
7            if(m == 1 || n == 1)
8                return 1;
9            if(hash.find(m) != hash.end() && hash[m].find(n) != hash[m].end())
10                return hash[m][n];
11            return hash[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
12        }
13};