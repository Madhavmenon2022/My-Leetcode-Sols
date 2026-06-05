# Last updated: 6/5/2026, 6:16:24 PM
1class Solution(object):
2    # @param obstacleGrid, a list of lists of integers
3    # @return an integer
4    def uniquePathsWithObstacles(self, obstacleGrid):
5        """
6        :type obstacleGrid: List[List[int]]
7        :rtype: int
8        """
9        m, n = len(obstacleGrid), len(obstacleGrid[0])
10
11        ways = [0]*n
12        ways[0] = 1
13        for i in xrange(m):
14            if obstacleGrid[i][0] == 1:
15                ways[0] = 0
16            for j in xrange(n):
17                if obstacleGrid[i][j] == 1:
18                    ways[j] = 0
19                elif j>0:
20                    ways[j] += ways[j-1]
21        return ways[-1]