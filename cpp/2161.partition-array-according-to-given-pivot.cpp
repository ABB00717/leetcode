/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
#include <vector>
class Solution {
public:
  std::vector<int> pivotArray(std::vector<int> &nums, int pivot) {
    std::vector<int> result;
    result.reserve(nums.size());

    for (const int& num : nums) {
      if (num < pivot) {
        result.push_back(num);
      }
    }
    
    for (const int& num : nums) {
      if (num == pivot) {
        result.push_back(num);
      }
    }
    
    for (const int& num : nums) {
      if (num > pivot) {
        result.push_back(num);
      }
    }

    return result;
  }
};
// @lc code=end
