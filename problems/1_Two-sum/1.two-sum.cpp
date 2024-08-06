// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndex;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = target - num;
            
            if (numToIndex.find(complement) != numToIndex.end()) 
                return {numToIndex[complement], i};
            numToIndex[num] = i;
        }

        return {};
    }
};
// @lc code=end

