// Last updated: 6/6/2026, 9:30:38 AM
1class Solution {
2    public:
3        bool exist(vector<vector<char> > &board, string word) {
4            const int m = board.size();
5            const int n = board.front().size();
6            vector<vector<bool> > visited(m, vector<bool> (n, false) );
7            for(int i = 0; i < m; ++i) {
8                for(int j = 0; j < n; ++j) {
9                    if(dfs(board, word, 0,  i, j, visited))
10                        return true;
11                }
12            }
13
14            return false;
15        }
16    private:
17        bool dfs(vector<vector<char> > &board, string word, int index, int i, int j,  vector<vector<bool> > &visited) {
18            if(index == word.size()) return true; // terminated condition
19
20            if(i < 0 || j < 0 || i >= board.size() || j >= board.front().size()  // pruning
21                    || visited[i][j] || board[i][j] != word[index])
22                return false;
23
24            visited[i][j] = true;  // set value
25            bool ret = dfs(board, word, index + 1,  i + 1, j, visited) 
26                || dfs(board, word, index + 1,  i, j + 1, visited) 
27                || dfs(board, word, index + 1,  i - 1, j, visited) 
28                || dfs(board, word, index + 1,  i, j - 1, visited);
29            visited[i][j] = false; // recover value
30
31            return ret;
32        }
33};