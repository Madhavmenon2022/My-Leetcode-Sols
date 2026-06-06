# Last updated: 6/6/2026, 9:37:29 AM
1class Solution(object):
2    # @return a boolean
3    def isScramble(self, s1, s2):
4        if not s1 or not s2 or len(s1) != len(s2):
5            return False
6        if s1 == s2:
7            return True
8        result = [[[False for j in xrange(len(s2))] for i in xrange(len(s1))] for n in xrange(len(s1) + 1)]
9        for i in xrange(len(s1)):
10            for j in xrange(len(s2)):
11                if s1[i] == s2[j]:
12                    result[1][i][j] = True
13
14        for n in xrange(2, len(s1) + 1):
15            for i in xrange(len(s1) - n + 1):
16                for j in xrange(len(s2) - n + 1):
17                    for k in xrange(1, n):
18                        if result[k][i][j] and result[n - k][i + k][j + k] or\
19                           result[k][i][j + n - k] and result[n - k][i + k][j]:
20                            result[n][i][j] = True
21                            break
22
23        return result[n][0][0]