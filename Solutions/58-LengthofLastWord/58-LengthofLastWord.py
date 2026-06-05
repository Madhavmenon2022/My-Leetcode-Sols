# Last updated: 6/5/2026, 6:17:09 PM
1class Solution(object):
2    # @param grid, a list of lists of integers
3    # @return an integer
4    def minPathSum(self, grid):
5        sum = list(grid[0])
6        for j in xrange(1, len(grid[0])):
7            sum[j] = sum[j - 1] + grid[0][j]
8
9        for i in xrange(1, len(grid)):
10            sum[0] += grid[i][0]
11            for j in xrange(1, len(grid[0])):
12                sum[j] = min(sum[j - 1], sum[j]) + grid[i][j]
13
14        return sum[-1]