// Last updated: 6/11/2026, 9:09:36 AM
1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        const auto& boyer_moore_majority_vote = [&]() {
5            int result = 0, cnt = 0;
6            for (const auto& x : nums) {
7                if (cnt == 0) {
8                    result = x;
9                }
10                if (x == result) {
11                    ++cnt;
12                } else {
13                    --cnt;
14                }
15            }
16            return result; 
17        };
18
19        return boyer_moore_majority_vote();
20    }
21};