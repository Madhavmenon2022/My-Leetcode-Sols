# Last updated: 6/16/2026, 6:10:55 PM
1class Solution(object):
2    # @return a boolean
3    def isInterleave(self, s1, s2, s3):
4        if len(s1) + len(s2) != len(s3):
5            return False
6        if len(s1) > len(s2):
7            return self.isInterleave(s2, s1, s3)
8        match = [False for i in xrange(len(s1) + 1)]
9        match[0] = True
10        for i in xrange(1, len(s1) + 1):
11            match[i] = match[i -1] and s1[i - 1] == s3[i - 1]
12        for j in xrange(1, len(s2) + 1):
13            match[0] = match[0] and s2[j - 1] == s3[j - 1]
14            for i in xrange(1, len(s1) + 1):
15                match[i] = (match[i - 1] and s1[i - 1] == s3[i + j - 1]) \
16                                       or (match[i] and s2[j - 1] == s3[i + j - 1])
17        return match[-1]
18