#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items, std::vector<int>& queries) {
    std::sort(items.begin(), items.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
      if (a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    });

    int max = 0;
    for (auto& item : items) {
      if (item[1] > max) max = item[1];
      item[1] = max;
    }

    std::vector<int> result;
    for (auto query : queries) {
      auto it = std::lower_bound(items.begin(), items.end(), std::vector<int>{query + 1, 0},
                                 [](const std::vector<int>& a, const std::vector<int>& b) {
                                   return a[0] < b[0];
                                 });

      if (it != items.begin()) {
        result.push_back((*(it - 1))[1]);
      } else {
        result.push_back(0);
      }
    }

    return result;
  }
};