#include <stack>
#include <utility>
#include <vector>
class Solution {
public:
  int countServers(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<int> row(m, 0), col(n, 0);
    std::stack<std::pair<int, int>> s;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          row[i]++;
          col[j]++;
          s.push({i, j});
        }
      }
    }

    int result = 0;
    while (!s.empty()) {
      auto [x, y] = s.top();
      s.pop();

      if (row[x] > 1 || col[y] > 1) {
        result++;
      }
    }

    return result;
  }
};
