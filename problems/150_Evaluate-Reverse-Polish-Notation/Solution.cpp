#include <algorithm>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

class Solution {
private:
  std::vector<char> operators = {'+', '-', '*', '/'};

  int calculate(int a, int b, char token) {
    int result = 0;

    switch (token) {
    case '+':
      result = a + b;
      break;
    case '-':
      result = a - b;
      break;
    case '*':
      result = a * b;
      break;
    case '/':
      result = static_cast<int>(a / b);
      break;
    default:
      throw std::invalid_argument("Invalid operator");
    }

    return result;
  }

public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> numbers;

    for (auto token : tokens) {
      if (std::find(operators.begin(), operators.end(), token[0]) ==
              operators.end() ||
          token.length() > 1) {
        numbers.push(std::stoi(token));
      } else {
        int b = numbers.top();
        numbers.pop();
        int a = numbers.top();
        numbers.pop();

        numbers.push(calculate(a, b, token[0]));
      }
    }

    return numbers.top();
  }
};
