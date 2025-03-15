/*
 * @lc app=leetcode id=2560 lang=cpp
 *
 * [2560] House Robber IV
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

class Solution {
   public:
    int minCapability(std::vector<int>& nums, int k) {
        int l = 0, r = *std::max_element(nums.begin(), nums.end());
        int minCap = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            int count = 0;
            int i = 0;
            while (i < nums.size()) {
                if (nums[i] <= m) {
                    count++;
                    i += 2;
                }  else {
                    i += 1;
                }
            }

            if (count >= k) {
                minCap = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return minCap;
    }
};

// @lc code=end