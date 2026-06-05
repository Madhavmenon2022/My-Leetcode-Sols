# Last updated: 6/5/2026, 4:01:47 PM
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def dfs(row):
            if row == n:
                result.append(map(lambda x: '.'*x + "Q" + '.'*(n-x-1), curr))
                return
            for i in xrange(n):
                if cols[i] or main_diag[row+i] or anti_diag[row-i+(n-1)]:
                    continue
                cols[i] = main_diag[row+i] = anti_diag[row-i+(n-1)] = True
                curr.append(i)
                dfs(row+1)
                curr.pop()
                cols[i] = main_diag[row+i] = anti_diag[row-i+(n-1)] = False

        result, curr = [], []
        cols, main_diag, anti_diag = [False]*n, [False]*(2*n-1), [False]*(2*n-1)
        dfs(0)
        return result