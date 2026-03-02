/*
 * @lc app=leetcode id=2962 lang=cpp
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        const int n = nums.size();
        const int maxElement = *std::max_element(nums.begin(), nums.end());
        
        long long subarrayCount = 0;
        int maxCount = 0, l = 0, lastMaxIndex = -1;
        for (int r = 0; r < n; r++) {
            if (nums[r] == maxElement) {
                maxCount++;
            }

            if (maxCount >= k) {
                while (l <= r && nums[l] != maxElement) {
                    l++;
                }
                subarrayCount += (long long)(l - lastMaxIndex) * (n - r);

                lastMaxIndex = l;
                l++;
                maxCount--;
            }
        }

        return subarrayCount;
    }
};
// @lc code=end

