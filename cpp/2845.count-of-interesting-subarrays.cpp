/*
 * @lc app=leetcode id=2845 lang=cpp
 *
 * [2845] Count of Interesting Subarrays
 */

// @lc code=start
#include <unordered_map>
#include <vector>
class Solution {
public:
    long long countInterestingSubarrays(std::vector<int>& nums, int modulo, int k) {
        std::vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + (nums[i] % modulo == k ? 1 : 0);
        }

        long long result = 0;
        std::unordered_map<int, int> counts;

        counts[0] = 1;

        for (int r = 0; r < nums.size(); r++) {
            int mod = prefix[r + 1] % modulo;
            int targetMod = (mod - k + modulo) % modulo;
            if (counts.count(targetMod))
                result += counts[targetMod];
            counts[mod]++;
        }

        return result;
    }
};
// @lc code=end

