#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  std::string smallestNumber(std::string pattern) { 
    std::string result;
    std::stack<char> stack;
    pattern += 'I';
    int num = 1;
    
    for (char ch : pattern) {
      stack.push((char)('0' + num));
      num++;

      if (ch == 'I') {
        while (!stack.empty()) {
          result += stack.top();
          stack.pop();
        }
      }
    }

    return result;
  }
};