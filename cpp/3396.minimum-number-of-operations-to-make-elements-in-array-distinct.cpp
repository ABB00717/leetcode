/*
 * @lc app=leetcode id=3396 lang=cpp
 *
 * [3396] Minimum Number of Operations to Make Elements in Array Distinct
 */

// @lc code=start
#include <cmath>
#include <unordered_map>
#include <vector>
class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        int n = nums.size();
        bool d[101] = {false};

        for (int i = n-1; i >= 0; i--) {
            if (d[nums[i]])
                return std::ceil((i+1) / 3.0);
            d[nums[i]] = true;            
        }

        return 0;
    }
};
// @lc code=end

