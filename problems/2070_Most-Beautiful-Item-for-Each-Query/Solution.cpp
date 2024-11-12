#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
public:
  std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items, std::vector<int> &queries) {
    std::sort(items.begin(), items.end(), [](const std::vector<int>& a, const std::vector<int>& b){
      return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
    });

    int max = 0;
    for (auto &item : items) {
      if (item[1] > max) max = item[1];
      item[1] = max;
    }

    std::vector<int> result;
    for (auto query : queries) {
      int left = 0, right = items.size() - 1;
      int bestBeauty = 0;

      while (left <= right) {
        int middle = left + (right - left) / 2;
        if (items[middle][0] <= query) {
          bestBeauty = items[middle][1];
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }

      result.push_back(bestBeauty);
    }

    return result;
  }
};