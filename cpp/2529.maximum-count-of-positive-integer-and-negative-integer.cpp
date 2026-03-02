/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
  int maximumCount(std::vector<int> &nums) {
    int pos = 0, neg = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        pos = nums.size() - i;
        break;
      } else if (nums[i] < 0) {
        neg++;
      }
    }

    return std::max(pos, neg);
  }
};
// @lc code=end
