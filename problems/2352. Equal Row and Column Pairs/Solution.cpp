#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
  int equalPairs(std::vector<std::vector<int>> &grid) {
    std::map<std::vector<int>, int> rowMap;

    for (auto row : grid) {
      rowMap[row]++;
    }

    int result = 0;
    for (int i = 0; i < grid[0].size(); i++) {
      std::vector<int> col(grid.size());

      for (int j = 0; j < grid.size(); j++) {
        col[j] = grid[j][i];
      }

      if (rowMap.count(col)) {
        result += rowMap[col];
      }
    }

    return result;
  }
};