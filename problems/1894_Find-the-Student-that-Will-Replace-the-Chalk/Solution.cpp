#include <vector>
#include <numeric>

class Solution {
public:
  int chalkReplacer(std::vector<int>& chalk, int k) {
    long long sum = std::accumulate(chalk.begin(), chalk.end(), 0); // Add 'std::' before 'accumulate'
    k %= sum;

    for (int i = 0; i < chalk.size(); i++) {
      if (k < chalk[i]) return i;
      k -= chalk[i];
    }

    return 0;
  }
};