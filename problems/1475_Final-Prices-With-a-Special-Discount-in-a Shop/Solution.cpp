#include <vector>
class Solution {
public:
  std::vector<int> finalPrices(std::vector<int> &prices) {
    for (int i = 0; i < prices.size(); i++) {
      int j = i+1;
      for (j = i+1; j < prices.size() && prices[j] > prices[i]; j++) {}
      if (j != prices.size()) prices[i] -= prices[j];
    }

    return prices;
  }
};