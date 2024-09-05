#include <numeric>
#include <vector>
class Solution {
public:
  std::vector<int> missingRolls(std::vector<int> &rolls, int mean, int n) {
    int rollsAccumulate = std::accumulate(rolls.begin(), rolls.end(), 0);
    int totalRoll = rolls.size() + n;
    int target = mean * totalRoll;

    if (rollsAccumulate + n > target || rollsAccumulate + n * 6 < target)
      return {};

    int remaining = target - rollsAccumulate;
    std::vector<int> result(n, remaining / n);
    int remainder = remaining % n;

    for (int i = 0; i < remainder; i++) {
      result[i]++;
    }

    return result;
  }
};
