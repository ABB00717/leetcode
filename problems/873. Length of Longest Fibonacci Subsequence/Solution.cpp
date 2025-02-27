#include <unordered_map>
#include <vector>
class Solution {
public:
  int lenLongestFibSubseq(std::vector<int> &arr) {
    int n = arr.size();
    
    std::unordered_map<int, int> index;
    std::unordered_map<int, std::unordered_map<int, int>> dp;

    for (int i = 0; i < n; ++i) {
      index[arr[i]] = i;
    }
    
    int maxLength = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int k = arr[i] - arr[j];
        if (index.count(k) && index[k] < j) {
          dp[j][i] = dp[index[k]][j] + 1;
        } else {
          dp[j][i] = 2;
        }

        maxLength = std::max(maxLength, dp[j][i]);
      }
    }

    return maxLength > 2 ? maxLength : 0;
  }
};