#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> diffWaysToCompute(std::string expression) {
    std::vector<int> result;

    for (int i = 0; i < expression.size(); i++) {
      char c = expression[i];
      if (c == '+' || c == '-' || c == '*') {
        std::vector<int> left = diffWaysToCompute(expression.substr(0, i));
        std::vector<int> right = diffWaysToCompute(expression.substr(i + 1));

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

    return result.empty() ? std::vector<int>{std::stoi(expression)} : result;
  }
};