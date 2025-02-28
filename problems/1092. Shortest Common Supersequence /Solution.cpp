  #include <string>
  #include <vector>
  class Solution {
  public:
    std::string shortestCommonSupersequence(std::string str1, std::string str2) {
      int m = str1.size(), n = str2.size();
      std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
      
      // init dp
      for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
          if (i == 0) {
            dp[i][j] = j;
          } else if (j == 0) {
            dp[i][j] = i;
          } else if (str1[i - 1] == str2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
          } else {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
          }
        }
      }

      // 回朔構造
      std::string result = "";
      int i = m, j = n;
      while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
          result += str1[i - 1];
          --i;
          --j;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
          result += str1[i - 1];
          --i;
        } else {
          result += str2[j - 1];
          --j;
        }
      }

      while (i > 0) {
        result += str1[i - 1];
        --i;
      }
      while (j > 0) {
        result += str2[j - 1];
        --j;
      }

      return std::string(result.rbegin(), result.rend());
    }
  };