/*
 * @lc app=leetcode id=2206 lang=cpp
 *
 * [2206] Divide Array Into Equal Pairs
 */

// @lc code=start
#include <vector>
class Solution {
   public:
    bool divideArray(std::vector<int>& nums) {
        std::vector<int> fqs(500, 0);

        for (const int& num : nums) {
            fqs[num]++;
        }

        for (const int& fq : fqs) {
            if (fq % 2 != 0)
                return false;
        }

        return true;
    }
};

// @lc code=end
