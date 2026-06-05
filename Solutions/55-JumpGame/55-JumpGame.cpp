// Last updated: 6/5/2026, 4:01:40 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i <= reachable && i < nums.size(); ++i) {
            reachable = max(reachable, i + nums[i]);
        }
        return reachable >= nums.size() - 1;
    }
};