#include <vector>

class Solution {
public:
  int chalkReplacer(std::vector<int>& chalk, int k) {
    std::vector<long long> prefixSum(chalk.size());
    prefixSum[0] = chalk[0];
    for (int i = 1; i < chalk.size(); i++) prefixSum[i] = prefixSum[i - 1] + chalk[i];

    k %= prefixSum.back();
    int l = 0, r = chalk.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (prefixSum[m] <= k) l = m + 1;
      else r = m;
    }

    return l;
  }
};