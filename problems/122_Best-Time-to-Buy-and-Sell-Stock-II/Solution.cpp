#include <vector>
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int earning = 0;
    int buy = prices[0];
    
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > buy)
        earning += prices[i] - buy;

      buy = prices[i];
    }

    return earning;
  }
};
