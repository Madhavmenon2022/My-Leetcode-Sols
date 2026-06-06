// Last updated: 6/6/2026, 9:32:05 AM
1class Solution {
2public:
3    bool search(vector<int> &nums, int target) {
4        int left = 0, right = nums.size() - 1;
5
6        while (left <= right) {
7            int mid = left + (right - left) / 2;
8            if (nums[mid] == target) {
9                return true;
10            } else if (nums[mid] == nums[left]) {
11                ++left;
12            } else if ((nums[mid] > nums[left] && nums[left] <= target && target < nums[mid]) ||
13                       (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
14                right = mid - 1;
15            } else {
16                left = mid + 1;
17            }
18        }
19
20        return false;
21    }
22};
23