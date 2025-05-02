/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <string>
class Solution {
public:
  int minimumRecolors(std::string blocks, int k) {
    int l = 0, r = 0, minWhite = 0, curWhite = 0;

    while (r < k) {
      if (blocks[r] == 'W')
        curWhite++;
      r++;
    }
    minWhite = curWhite;

    while (r < blocks.size()) {
      if (blocks[r] == 'W')
        curWhite++;
      if (blocks[l] == 'W')
        curWhite--;

      minWhite = std::min(minWhite, curWhite);
      r++;
      l++;
    }

    return minWhite;
  }
};
// @lc code=end
