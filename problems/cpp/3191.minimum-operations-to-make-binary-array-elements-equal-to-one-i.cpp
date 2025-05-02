/*
 * @lc app=leetcode id=3191 lang=cpp
 *
 * [3191] Minimum Operations to Make Binary Array Elements Equal to One I
 */

// @lc code=start
#include <vector>
class Solution {
   public:
    int minOperations(std::vector<int>& nums) {
        int l = 0, count = 0, n = nums.size();
        for (int l = 0; l < nums.size() - 2; l++) {
            if (nums[l] == 0) {
                count++;
                nums[l] ^= 1;
                nums[l+1] ^= 1;
                nums[l+2] ^= 1;
            }
        }

        if (nums[n-2] == 0 || nums[n-1] == 0)
            return -1;

        return count;
    }
};

// @lc code=end
