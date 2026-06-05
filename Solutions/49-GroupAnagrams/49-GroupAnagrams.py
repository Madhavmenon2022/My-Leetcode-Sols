# Last updated: 6/5/2026, 3:55:14 PM
1class Solution(object):
2    def totalNQueens(self, n):
3        """
4        :type n: int
5        :rtype: int
6        """
7        def dfs(row):
8            if row == n:
9                return 1
10            result = 0
11            for i in xrange(n):
12                if cols[i] or main_diag[row+i] or anti_diag[row-i+(n-1)]:
13                    continue
14                cols[i] = main_diag[row+i] = anti_diag[row-i+(n-1)] = True
15                result += dfs(row+1)
16                cols[i] = main_diag[row+i] = anti_diag[row-i+(n-1)] = False
17            return result
18
19        result = []
20        cols, main_diag, anti_diag = [False]*n, [False]*(2*n-1), [False]*(2*n-1)
21        return dfs(0)