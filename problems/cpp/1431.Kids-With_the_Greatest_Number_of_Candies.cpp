#include <algorithm>
#include <vector>
class Solution {
public:
  std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies) {
    int maxCandies = *std::max_element(candies.begin(), candies.end());

    std::vector<bool> result(candies.size());
    for (int i = 0; i < candies.size(); ++i) {
      result[i] = candies[i] + extraCandies >= maxCandies;
    }

    return result;
  }
};