/*
 * @lc app=leetcode id=2799 lang=cpp
 *
 * [2799] Count Complete Subarrays in an Array
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
    int countCompleteSubarrays(std::vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();

        std::unordered_set<int> unique_elements(nums.begin(), nums.end());
        int unique_count = unique_elements.size();

        int complete_count = 0;
        std::pmr::unordered_map<int, int> current_elements;
        while (r < n) {
            current_elements[nums[r]]++;
            while (current_elements.size() == unique_count && l <= r) {
                complete_count += n - r;
                if (--current_elements[nums[l]] == 0) {
                    current_elements.erase(nums[l]);
                }
                l++;
            }

            r++;
        }

        return complete_count;
    }
};
// @lc code=end

