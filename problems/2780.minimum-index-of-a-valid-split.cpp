/*
 * @lc app=leetcode id=2780 lang=cpp
 *
 * [2780] Minimum Index of a Valid Split
 */

// @lc code=start
#include <unordered_map>
#include <vector>
class Solution {
   public:
    int minimumIndex(std::vector<int>& nums) {
        int n = nums.size();
        
        int dominant = -1, count = 0;
        for (const int& num : nums) {
            if (count == 0) {
                dominant = num;
                count = 1;
            } else if (dominant == num) {
                count++;
            } else {
                count--;
            }
        }
        
        if (dominant == -1)
            return -1;

        int totalCount = 0;
        for (const int& num : nums)
            if (num == dominant)
                totalCount++;
        
        std::vector<int> preSum(n, 0), postSum(n, 0);
        int preCur = 0, postCur = totalCount;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == dominant) {
                preCur++;
                postCur--;
            }

            int leftSize = i + 1;
            int rightSize = n - leftSize;
            if (preCur * 2 > leftSize && postCur * 2 > rightSize)
                return i;
        }

        return -1;
    }
};

// @lc code=end
