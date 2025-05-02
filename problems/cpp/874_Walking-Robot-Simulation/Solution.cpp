#include <set>
#include <utility>
#include <vector>
class Solution {
public:
  int robotSim(std::vector<int> &commands, std::vector<std::vector<int>> &obstacles) {
    int x = 0, y = 0, direction = 0, maxDistance = 0;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::set<std::pair<int, int>> obstacleSet;

    for (auto obstacle : obstacles) {
      obstacleSet.insert({obstacle[0], obstacle[1]});
    }

    for (int command : commands) {
      if (command == -1) {
        direction = (direction + 1) % 4;
      } else if (command == -2) {
        direction = (direction + 3) % 4;
      } else {
        for (int i = 0; i < command; i++) {
          int nextX = x + directions[direction].first;
          int nextY = y + directions[direction].second;

          if (obstacleSet.find({nextX, nextY}) == obstacleSet.end()) {
            x = nextX;
            y = nextY;
            maxDistance = std::max(maxDistance, x * x + y * y);
          }
        }
      }
    }

    return maxDistance;
  }
};