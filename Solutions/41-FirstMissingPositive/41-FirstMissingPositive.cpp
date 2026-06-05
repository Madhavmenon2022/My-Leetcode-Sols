// Last updated: 6/5/2026, 3:36:58 PM
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < size(nums); ++i) {
            while (1 <= nums[i] && nums[i] <= size(nums) && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size(nums) + 1;
    }
};