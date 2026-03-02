/*
 * @lc app=leetcode id=3375 lang=cpp
 *
 * [3375] Minimum Operations to Make Array Values Equal to K
 */

// @lc code=start
#include <unordered_set>
#include <vector>
class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::unordered_set<int> s;

        for (const int& num : nums) {
            if (num < k)
                return -1;

            if (num > k)
                s.insert(num);
            
        }

        return s.size();
    }
};
// @lc code=end

