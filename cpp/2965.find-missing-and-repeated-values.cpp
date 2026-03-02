/*
 * @lc app=leetcode id=2965 lang=cpp
 *
 * [2965] Find Missing and Repeated Values
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <iterator>
#include <unordered_set>
#include <vector>
class Solution {
public:
  std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>> &grid) {
    int n = grid.size(), nn = std::pow(n, 2);
    std::vector<int> freq(nn+1, 0);
    
    int repeated = 0;
    for (const auto& row : grid) {
      for (int ele : row) {
        if (freq[ele] == 1)
          repeated = ele;
        else
          freq[ele]++;
      }
    }

    for (int i = 1; i <= nn; i++) {
      if (freq[i] == 0)
        return {repeated, i};
    }

    return {-1, -1};
  }
};
// @lc code=end
