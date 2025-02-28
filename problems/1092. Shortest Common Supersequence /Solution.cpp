#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::string shortestCommonSupersequence(std::string str1, std::string str2) {
    int m = str1.size(), n = str2.size();
    std::vector<std::vector<std::string>> dp(m+1, std::vector<std::string>(n+1, ""));
    
    // init dp
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (i == 0) {
          dp[i][j] = str2.substr(0, j);
        } else if (j == 0) {
          dp[i][j] = str1.substr(0, i);
        } else if (str1[i - 1] == str2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
        } else {
          if (dp[i - 1][j].size() < dp[i][j - 1].size()) {
            dp[i][j] = dp[i - 1][j] + str1[i - 1];
          } else if (dp[i - 1][j].size() > dp[i][j - 1].size()) {
            dp[i][j] = dp[i][j - 1] + str2[j - 1];
          } else {
            dp[i][j] = (dp[i - 1][j] + str1[i - 1] < dp[i][j - 1] + str2[j - 1]) ? (dp[i - 1][j] + str1[i - 1]) : (dp[i][j - 1] + str2[j - 1]);
          }
        }
      }
    }

    return dp[m][n];
  }
};