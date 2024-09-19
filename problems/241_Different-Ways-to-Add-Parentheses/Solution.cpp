#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<int> diffWaysToCompute(std::string expression) {
    return helper(expression);
  }
  
private:
  std::unordered_map<std::string, std::vector<int>> memo;
  
  std::vector<int> helper(const std::string& expression) {
    if (memo.find(expression) != memo.end()) {
      return memo[expression];
    }
    
    std::vector<int> result;
    for (int i = 0; i < expression.size(); i++) {
      char c = expression[i];
      if (c == '+' || c == '-' || c == '*') {
        std::vector<int> left = helper(expression.substr(0, i));
        std::vector<int> right = helper(expression.substr(i + 1));
        for (int l : left) {
          for (int r : right) {
            if (c == '+') {
              result.push_back(l + r);
            } else if (c == '-') {
              result.push_back(l - r);
            } else {
              result.push_back(l * r);
            }
          }
        }
      }
    }
    if (result.empty()) {
      result.push_back(std::stoi(expression));
    }
    memo[expression] = result;
    return result;
  }
};
