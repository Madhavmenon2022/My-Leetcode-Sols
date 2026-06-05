// Last updated: 6/5/2026, 8:49:33 PM
1class Solution {
2public:
3    vector<vector<int>> combine(int n, int k) {
4        static const auto& add_result =
5            [](const auto& nums, const auto& idxs, auto *result) {
6                result->emplace_back();
7                transform(cbegin(idxs), cend(idxs), back_inserter(result->back()),
8                          [&nums](const auto& i) {
9                              return nums[i];
10                          });
11            };
12        static const auto& next_pos =
13            [](const auto& n, const auto& k, const auto& idxs) {
14                int i = k - 1;
15                for (; i >= 0; --i) {
16                    if (idxs[i] != i + n - k) {
17                        break;
18                    }
19                }
20                return i;
21            };
22
23        if (k > n) {
24            return {};
25        }
26        vector<int> nums(n), idxs(k);
27        iota(begin(nums), end(nums), 1), iota(begin(idxs), end(idxs), 0);
28        vector<vector<int>> result;
29        add_result(nums, idxs, &result);
30        for (int i; (i = next_pos(n, k, idxs)) >= 0;) {
31            ++idxs[i];
32            for (int j = i + 1; j < k; ++j) {
33                idxs[j] = idxs[j - 1] + 1;
34            }
35            add_result(nums, idxs, &result);
36        }
37        return result;
38    }
39};
40