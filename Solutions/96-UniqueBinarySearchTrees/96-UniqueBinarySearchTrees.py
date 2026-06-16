# Last updated: 6/16/2026, 6:10:16 PM
1class Solution(object):
2    def numTrees(self, n):
3        """
4        :type n: int
5        :rtype: int
6        """
7        if n == 0:
8            return 1
9
10        def combination(n, k):
11            count = 1
12            # C(n, k) = (n) / 1 * (n - 1) / 2 ... * (n - k + 1) / k
13            for i in xrange(1, k + 1):
14                count = count * (n - i + 1) / i
15            return count
16
17        return combination(2 * n, n) - combination(2 * n, n - 1)
18