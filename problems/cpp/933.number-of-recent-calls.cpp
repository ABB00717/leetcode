/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
#include <algorithm>
#include <deque>
class RecentCounter {
private:
  std::deque<int> timeSeq;
public:
  RecentCounter() {

  }

  int ping(int t) {
    int l = std::max(0, t-3000);
    timeSeq.push_back(t);

    while (timeSeq.front() < l) {
      timeSeq.pop_front();
    }

    return timeSeq.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
