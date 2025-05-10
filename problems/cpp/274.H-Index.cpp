#include <algorithm>
#include <functional>
#include <vector>
class Solution {
public:
  int hIndex(std::vector<int> &citations) {
    std::sort(citations.begin(), citations.end(), std::greater<int>());

    int result = 0;
    for (int i = 0; i < citations.size(); i++) {
      if (citations[i] >= i + 1) result = i + 1;
    }

    return result;
  }
};