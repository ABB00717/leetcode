#include <stack>
#include <string>
class Solution {
public:
  std::string removeStars(std::string s) {
    std::stack<char> stack;
    std::string result;

    for (char ch : s) {
      if (ch == '*') {
        stack.pop();
      } else {
        stack.push(ch);
      }
    }

    while (!stack.empty()) {
      result.insert(result.begin(), stack.top());
      stack.pop();
    }

    return result;
  }
};