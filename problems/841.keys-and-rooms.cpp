/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
#include <set>
#include <vector>
class Solution {
public:
  bool canVisitAllRooms(std::vector<std::vector<int>> &rooms) {
    std::set<int> visited;
    visited.insert(0);

    for (int key : rooms[0]) {
      dfs(key, rooms, visited);
    }

    return visited.size() == rooms.size();
  }
private:
  void dfs(int key, std::vector<std::vector<int>> rooms, std::set<int>& visited) {
    if (visited.count(key))
      return;
    
    visited.insert(key);
    for (int key : rooms[key]) {
      dfs(key, rooms, visited);
    }
  }
};
// @lc code=end
