/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
#include <algorithm>
#include <deque>
#include <string>
class Solution {
private:
  void banOpponent(std::deque<int>& exchange, std::deque<int>& pop, int& i) {
    i = exchange.front();
    exchange.push_back(i);
    exchange.pop_front();
    pop.pop_front();
  }

public:
  std::string predictPartyVictory(std::string senate) {
    std::deque<int> dDeque, rDeque;

    for (int i = 0; i < senate.size(); i++) {
      if (senate[i] == 'R') {
        rDeque.push_back(i);
      } else if (senate[i] == 'D') {
        dDeque.push_back(i);
      }
    }

    int lastIndex = -1;
    while (!dDeque.empty() && !rDeque.empty()) {
      if (lastIndex >= dDeque.front() && lastIndex >= rDeque.front()) {
        lastIndex = std::min(dDeque.front(), rDeque.front());

        if (lastIndex == dDeque.front()) {
          dDeque.push_back(lastIndex);
        } else {
          rDeque.push_back(lastIndex);
        }
        rDeque.pop_front();
        dDeque.pop_front();
      } else if (lastIndex >= dDeque.front()) {
        banOpponent(rDeque, dDeque, lastIndex);
      } else if (lastIndex >= rDeque.front()) {
        banOpponent(dDeque, rDeque, lastIndex);
      } else {
        if (dDeque.front() > rDeque.front()) {
          banOpponent(rDeque, dDeque, lastIndex);
        } else {
          banOpponent(dDeque, rDeque, lastIndex);
        }
      }
    }

    return dDeque.empty() ? "Radiant" : "Dire";
  }
};
// @lc code=end
