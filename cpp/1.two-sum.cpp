/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> nti;

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (nti.count(comp))
                return {nti[comp], i};

            nti[nums[i]] = i;
        }

        return {};
    }
};

// @lc code=end
