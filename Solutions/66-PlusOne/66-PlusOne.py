# Last updated: 6/5/2026, 8:43:10 PM
1class Solution(object):
2    # @return an integer
3    def minDistance(self, word1, word2):
4        if len(word1) < len(word2):
5            return self.minDistance(word2, word1)
6
7        distance = [i for i in xrange(len(word2) + 1)]
8
9        for i in xrange(1, len(word1) + 1):
10            pre_distance_i_j = distance[0]
11            distance[0] = i
12            for j in xrange(1, len(word2) + 1):
13                insert = distance[j - 1] + 1
14                delete = distance[j] + 1
15                replace = pre_distance_i_j
16                if word1[i - 1] != word2[j - 1]:
17                    replace += 1
18                pre_distance_i_j = distance[j]
19                distance[j] = min(insert, delete, replace)
20
21        return distance[-1]
22