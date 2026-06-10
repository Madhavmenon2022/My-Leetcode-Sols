// Last updated: 6/10/2026, 9:28:26 AM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        if (nums.empty()) return 0;
5
6        int max_so_far = nums[0];
7        int min_so_far = nums[0];
8        int result = nums[0];
9        
10
11        for (int i = 1; i < nums.size(); ++i) {
12            int current = nums[i];
13
14            if (current < 0) {
15                swap(max_so_far, min_so_far);
16            }
17
18            max_so_far = max(current, max_so_far * current);
19            min_so_far = min(current, min_so_far * current);
20
21            result = max(result, max_so_far);
22        }
23
24        return result;
25    }
26};