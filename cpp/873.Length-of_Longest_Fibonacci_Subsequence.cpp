#include <unordered_map>
#include <vector>
class Solution {
public:
  int lenLongestFibSubseq(std::vector<int> &arr) {
    int n = arr.size();
    
    std::unordered_map<int, int> index;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 2));

    for (int i = 0; i < n; ++i) {
      index[arr[i]] = i;
    }
    
    int maxLength = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int k = arr[i] - arr[j];
        if (index.count(k) && index[k] < j) {
          int k_index = index[k];
          dp[j][i] = dp[k_index][j] + 1;
          maxLength = std::max(maxLength, dp[j][i]);
        }
      }
    }

    return maxLength > 2 ? maxLength : 0;
  }
};