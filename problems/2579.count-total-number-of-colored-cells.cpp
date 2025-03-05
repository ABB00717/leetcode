/*
 * @lc app=leetcode id=2579 lang=cpp
 *
 * [2579] Count Total Number of Colored Cells
 */

// @lc code=start
#include <vector>
class Solution {
public:
  long long coloredCells(int n) {
    long long result = n*(n+1)/2 + n*(n-1);
    return n > 2 ? result + (n-1)*(n-2)/2 : result;
  }
};
// @lc code=end
