// Last updated: 6/6/2026, 9:31:21 AM
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        if (nums.empty()) {
5            return 0;
6        }
7
8        const int k = 2; // At most k duplicated.
9
10        int left = 0;
11        int right = 1;
12
13        while (right < nums.size()) {
14            if (nums[left] != nums[right] ||
15                (left - k + 1 < 0 || nums[left] != nums[left - k + 1])) {
16                ++left;
17                nums[left] = nums[right];
18            }
19            ++right;
20        }
21
22        return left + 1; 
23    }
24};