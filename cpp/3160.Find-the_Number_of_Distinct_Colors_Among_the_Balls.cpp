#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> queryResults(int limit,
                                std::vector<std::vector<int>> &queries) {
    std::unordered_map<int, int> colorCount; // 追蹤每種顏色的出現次數
    std::unordered_map<int, int> colors;     // 只存有顏色的球
    std::vector<int> result;
    int distinctColors = 0;

    for (const auto &query : queries) {
      int ball = query[0];
      int newColor = query[1];
      int currentColor = colors[ball]; // 取得當前球的顏色（若未標記過，則為 0）

      // 移除舊顏色
      if (currentColor != 0) {
        colorCount[currentColor]--;
        if (colorCount[currentColor] == 0) {
          distinctColors--; // 如果舊顏色的計數歸零，則 distinctColors 減少
          colorCount.erase(currentColor); // 移除記錄，減少記憶體使用
        }
      }

      // 標記新顏色
      colors[ball] = newColor;
      if (colorCount[newColor] == 0) {
        distinctColors++; // 如果新顏色是第一次出現，則 distinctColors 增加
      }
      colorCount[newColor]++;

      result.push_back(distinctColors);
    }

    return result;
  }
};
