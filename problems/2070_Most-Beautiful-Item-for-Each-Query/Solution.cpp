#include <random>
#include <utility>
#include <vector>
#include <algorithm>

class Solution {
private:
  std::mt19937 rng;

  int randomRange(int left, int right) {
    std::uniform_int_distribution<std::mt19937::result_type> randIndex(left, right);
    return randIndex(rng);
  }

  void quickSort(std::vector<std::vector<int>>& items, int left, int right) {
    if (left >= right) return;

    std::swap(items[left], items[randomRange(left, right)]);
    int middle = left;

    for (int i = left + 1; i <= right; i++) {
      if (items[i][0] < items[left][0] || (items[i][0] == items[left][0] && items[i][1] > items[left][1])) {
        std::swap(items[++middle], items[i]);
      }
    }

    std::swap(items[left], items[middle]);
    quickSort(items, left, middle - 1);
    quickSort(items, middle + 1, right);
  }
  
public:
  Solution() : rng(std::random_device{}()) {}

  std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items, std::vector<int> &queries) {
    quickSort(items, 0, items.size() - 1);

    int max = 0;
    for (auto& item : items) {
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