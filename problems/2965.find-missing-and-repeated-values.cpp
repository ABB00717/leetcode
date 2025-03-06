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
    std::unordered_set<int> allInt;
    allInt.reserve(std::pow(n, 2));
    for (int i = 1; i <= nn; i++)
      allInt.insert(i);
    
    int a, b;
    for (const auto& row : grid) {
      for (int ele : row) {
        if (!allInt.count(ele))
          a = ele;
        else
          allInt.erase(ele);
      }
    }

    b = *allInt.begin();

    return {a, b};
  }
};
// @lc code=end
