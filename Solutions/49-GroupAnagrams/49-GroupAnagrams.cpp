// Last updated: 6/5/2026, 4:00:30 PM
1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int reachable = 0;
5        for (int i = 0; i <= reachable && i < nums.size(); ++i) {
6            reachable = max(reachable, i + nums[i]);
7        }
8        return reachable >= nums.size() - 1;
9    }
10};