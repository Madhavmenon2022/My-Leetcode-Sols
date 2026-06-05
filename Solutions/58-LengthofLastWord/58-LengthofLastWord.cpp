// Last updated: 6/5/2026, 6:12:52 PM
1class Solution {
2public:
3    string getPermutation(int n, int k) {
4        vector<int> nums;
5        int total = 1;
6        for (int i = 1; i <= n; ++i) {
7            nums.emplace_back(i);
8            total *= i;
9        }
10
11        // Cantor Ordering:
12        // Construct the k-th permutation with a list of n numbers
13        // Idea: group all permutations according to their first number (so n groups, each of
14        // (n - 1)! numbers), find the group where the k-th permutation belongs, remove the common
15        // first number from the list and append it to the resulting string, and iteratively
16        // construct the (((k - 1) % (n - 1)!) + 1)-th permutation with the remaining n-1 numbers
17        int group = total;
18        stringstream permutation;
19        while (n > 0) {
20            group /= n;
21            int idx = (k - 1) / group;
22            permutation << nums[idx];
23            nums.erase(nums.begin() + idx);
24            k = (k - 1) % group + 1;
25            --n;
26        }
27
28        return permutation.str();
29    }
30};