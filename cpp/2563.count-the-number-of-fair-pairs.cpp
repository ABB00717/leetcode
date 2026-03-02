/*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());

        long long count = 0;
        int l = nums.size()-1, r = nums.size()-1;
        for (int i = 0; i < nums.size(); i++) {
            while (l > i && nums[i] + nums[l] >= lower) {
                l--;
            }

            while (r > i && nums[i] + nums[r] > upper) {
                r--;
            }

            if (l <= i && r <= i) {
                break;
            }

            l = std::max(l, i);
            r = std::max(r, i);
            count += r - l;
        }

        return count;
    }
};
// @lc code=end
// 0 1 2 3 4 5
// 0 1 4 4 5 7, 3 | 6
/*
i = 0, l = 1, r = 4 -> r - l = 3
i = 1, l = 1, r = 4 -> r - l = 3
i = 2, l = 1, r = 2 -> break
*/