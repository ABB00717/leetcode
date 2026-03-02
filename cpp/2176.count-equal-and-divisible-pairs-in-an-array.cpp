/*
 * @lc app=leetcode id=2176 lang=cpp
 *
 * [2176] Count Equal and Divisible Pairs in an Array
 */

// @lc code=start
#include <vector>
class Solution {
   public:
    int countPairs(std::vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    res++;
                }
            }
        }

        return res;
    }
};

// @lc code=end
