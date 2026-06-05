# Last updated: 6/5/2026, 3:54:33 PM
1class Solution(object):
2    def solveNQueens(self, n):
3        """
4        :type n: int
5        :rtype: List[List[str]]
6        """
7        def dfs(row):
8            if row == n:
9                result.append(map(lambda x: '.'*x + "Q" + '.'*(n-x-1), curr))
10                return
11            for i in xrange(n):
12                if cols[i] or main_diag[row+i] or anti_diag[row-i+(n-1)]:
13                    continue
14                cols[i] = main_diag[row+i] = anti_diag[row-i+(n-1)] = True
15                curr.append(i)
16                dfs(row+1)
17                curr.pop()
18                cols[i] = main_diag[row+i] = anti_diag[row-i+(n-1)] = False
19
20        result, curr = [], []
21        cols, main_diag, anti_diag = [False]*n, [False]*(2*n-1), [False]*(2*n-1)
22        dfs(0)
23        return result