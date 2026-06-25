# Last updated: 6/25/2026, 6:21:11 PM
1class Solution(object):
2    # @return an integer
3    def numDistinct(self, S, T):
4        ways = [0 for _ in xrange(len(T) + 1)]
5        ways[0] = 1
6        for S_char in S:
7            for j, T_char in reversed(list(enumerate(T))):
8                if S_char == T_char:
9                    ways[j + 1] += ways[j]
10        return ways[len(T)]