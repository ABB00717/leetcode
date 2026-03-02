#include <climits>
#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>>
  highestPeak(std::vector<std::vector<int>> &isWater) {
    int m = isWater.size();
    int n = isWater[0].size();
    std::vector<std::vector<int>> result(m, std::vector<int>(n, -1));
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (isWater[i][j] == 1) {
          result[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (auto [dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            result[nx][ny] == -1) {
          result[nx][ny] = result[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    return result;
  }
};