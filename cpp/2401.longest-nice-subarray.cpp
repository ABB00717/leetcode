/*
 * @lc app=leetcode id=2401 lang=cpp
 *
 * [2401] Longest Nice Subarray
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
   public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int cur = 0, l = 0, r = 0, maxSection = 0;
        while (r < nums.size()) {
            while ((nums[r] + cur) != (nums[r] | cur)) {
                cur -= nums[l++];
            }

            cur += nums[r++];
            maxSection = std::max(r - l, maxSection);
        }

        return maxSection;
    }
};

// @lc code=end
