/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
#include <queue>
#include <string>
class Solution {
public:
  std::string predictPartyVictory(std::string senate) {
    std::queue<int> rQueue, dQueue;
    int n = senate.size();

    for (int i = 0; i < n; i++) {
      if (senate[i] == 'R') {
        rQueue.push(i);
      } else {
        dQueue.push(i);
      }
    }

    while (!rQueue.empty() && !dQueue.empty()) {
      int rIndex = rQueue.front();
      int dIndex = dQueue.front();
      rQueue.pop();
      dQueue.pop();

      if (rIndex < dIndex) {
        rQueue.push(rIndex + n);
      } else {
        dQueue.push(dIndex + n);
      }

    }

    return rQueue.empty() ? "Dire" : "Radiant";
  }
};
// @lc code=end
