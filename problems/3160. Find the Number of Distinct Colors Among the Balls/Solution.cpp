#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> queryResults(int limit,
                                std::vector<std::vector<int>> &queries) {
    std::unordered_map<int, int> count; // 記錄每個顏色的數量
    std::vector<int> result;
    std::vector<int> colors(limit + 1, 0); // 確保大小為 limit + 1

    int distinctColors = 0;

    for (const auto &query : queries) {
      int ball = query[0];
      int newColor = query[1];
      int currentColor = colors[ball]; // 取得目前球的顏色

      // 如果球已經有顏色，則先減少該顏色的數量
      if (currentColor != 0) {
        count[currentColor]--;
        if (count[currentColor] == 0) {
          distinctColors--; // 如果該顏色不再出現，則從 distinctColors 減去
        }
      }

      // 更新球的顏色
      colors[ball] = newColor;

      // 增加新顏色的數量
      if (count[newColor] == 0) {
        distinctColors++; // 如果該顏色是第一次出現，則增加 distinctColors
      }
      count[newColor]++;

      // 記錄當前的 distinctColors
      result.push_back(distinctColors);
    }

    return result;
  }
};
