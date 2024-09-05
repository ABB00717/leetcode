  #include <algorithm>
  #include <numeric>
  #include <vector>
  class Solution {
  public:
    std::vector<int> missingRolls(std::vector<int> &rolls, int mean, int n) {
      std::vector<int> result(n, 0);

      int rollsAccumulate = std::accumulate(rolls.begin(), rolls.end(), 0);
      int totalRoll = rolls.size() + n;
      int target = mean * totalRoll;

      if (rollsAccumulate + n > target || rollsAccumulate + n * 6 < target) return {};

      int remaining = target - rollsAccumulate;

      for (int i = 0; i < n; i++) {
        int roll = std::max(1, static_cast<int>((remaining) / (n - i)));
        result[i] = roll;
        remaining -= roll;
      }

      return result;
    }
  };
