/*
 * @lc app=leetcode id=3208 lang=cpp
 *
 * [3208] Alternating Groups II
 */

// @lc code=start
#include <vector>
class Solution {
public:
  int numberOfAlternatingGroups(std::vector<int> &colors, int k) {
    const int n = colors.size(), sz = (n + k) - 1;
    int result = 0, prevColor = colors[0], section = 1;
    
    for (int i = 1; i < sz; i++) {
      section = prevColor == colors[i%n] ? 1 : section + 1;
      result += (section >= k);
      prevColor = colors[i%n];
    }

    return result;
  }
};
// @lc code=end
