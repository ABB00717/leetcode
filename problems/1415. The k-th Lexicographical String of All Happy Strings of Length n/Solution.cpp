#include <cmath>
#include <string>
#include <vector>
class Solution {
private:
  void dfs(std::vector<std::string> &happyStrings, std::string current, int n, int k) {
    if (happyStrings.size() == k)
      return;

    if (current.size() == n) {
      happyStrings.push_back(current);
      return;
    }

    for (char ch = 'a'; ch <= 'c'; ch++) {
      if (current.empty() || current.back() != ch) {
        dfs(happyStrings, current + ch, n, k);
      }
    }
  }
  
public:
  std::string getHappyString(int n, int k) {
    if (3 * (std::pow(2, n - 1)) < k)
      return "";

    std::vector<std::string> happyStrings;
    dfs(happyStrings, "", n, k);
    return happyStrings[k - 1];
  }
};