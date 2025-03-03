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
    std::vector<int> less, mid, greater;

    for (const int& num : nums) {
      if (num < pivot) {
        less.push_back(num);
      } else if (num == pivot) {
        mid.push_back(num);
      } else {
        greater.push_back(num);
      }
    }

    std::vector<int> result(less.begin(), less.end());
    for (const int& num : mid) {
      result.push_back(num);
    }
    for (const int& num : greater) {
      result.push_back(num);
    }
    return result;
  }
};
// @lc code=end
