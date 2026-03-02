/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <vector>
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        // If the total sum is odd, we cannot partition it into two equal subsets.
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        // dp[i] will be true if a subset with sum i can be formed using the elements of nums.
        std::vector<bool> dp(target + 1, false);
        dp[0] = true; // A sum of 0 can always be formed with an empty subset.

        for (int num : nums) {
            // Traverse the dp array backwards to avoid using the same number multiple times.
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target]; // Return whether a subset with the target sum can be formed.
    }
};
// @lc code=end

