/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
#include <vector>
class Solution {
   public:
    int findNumbers(std::vector<int>& nums) {
        int result = 0;

        for (int& num : nums) {
            int digitCount = 0;

            while (num > 0) {
                digitCount++;
                num /= 10;
            }

            if (digitCount % 2 == 0) {
                result++;
            }
        }

        return result;
    }
};

// @lc code=end
