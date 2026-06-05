// Last updated: 6/5/2026, 4:01:45 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = numeric_limits<int>::min();
        int curr = numeric_limits<int>::min();
        for (const auto &x : nums) {
            curr = (curr == numeric_limits<int>::min()) ? x : max(curr + x, x);
            result = max(result, curr);
        }
        return result;
    }
};