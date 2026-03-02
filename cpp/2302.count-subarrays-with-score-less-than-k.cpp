/*
 * @lc app=leetcode id=2302 lang=cpp
 *
 * [2302] Count Subarrays With Score Less Than K
 */

// @lc code=start
#include <vector>

class Solution {
   public:
    long long countSubarrays(std::vector<int>& nums, long long k) {
        int n = nums.size();
        int left = 0;
        long long count = 0;
        long long sum = 0;
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (left <= right && sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }
            
            count += right - left + 1;
        }

        return count;
    }
};
// @lc code=end
