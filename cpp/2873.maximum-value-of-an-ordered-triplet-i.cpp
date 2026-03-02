/*
 * @lc app=leetcode id=2873 lang=cpp
 *
 * [2873] Maximum Value of an Ordered Triplet I
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
    public:
        // To maximize (nums[i] - nums[j]) * nums[k] 
        // We want nums[i] and nums[k] to be as large as possible, and nums[j] to be smaller.
        // So we treat each index j as the middle point,
        // and precompute the maximums to its left (prefix) and right (suffix).
        long long maximumTripletValue(std::vector<int>& nums) {
            int n = nums.size();
    
            // prefixMax[i] stores the maximum value among nums[0] to nums[i]
            std::vector<int> prefixMax(n);
            prefixMax[0] = nums[0];
            for (int i = 1; i < n; ++i)
                prefixMax[i] = std::max(prefixMax[i - 1], nums[i]);
    
            // suffixMax[i] stores the maximum value among nums[i] to nums[n-1]
            std::vector<int> suffixMax(n);
            suffixMax[n - 1] = nums[n - 1];
            for (int i = n - 2; i >= 0; --i)
                suffixMax[i] = std::max(suffixMax[i + 1], nums[i]);
    
            long long result = 0;
            // Try every possible j in the middle of the triplet
            for (int j = 1; j < n - 1; ++j) {
                // Best nums[i] is the max value before j
                long long left = prefixMax[j - 1];
                // Best nums[k] is the max value after j
                long long right = suffixMax[j + 1];
                // Only consider the case when left > nums[j]
                if (left > nums[j])
                    result = std::max(result, (left - nums[j]) * right);
            }
    
            return result;
        }
    };
    

// @lc code=end
