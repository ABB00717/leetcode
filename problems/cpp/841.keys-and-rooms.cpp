/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
#include <queue>
#include <set>
#include <vector>
class Solution {
public:
  bool canVisitAllRooms(std::vector<std::vector<int>> &rooms) {
    int n = rooms.size();
    std::set<int> visited;
    std::queue<int> q;
    q.push(0);
    visited.insert(0);

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int key : rooms[node]) {
        if (!visited.count(key)) {
          q.push(key);
          visited.insert(key);
        }
      }
    }

    return visited.size() == rooms.size();
  }
};
// @lc code=end