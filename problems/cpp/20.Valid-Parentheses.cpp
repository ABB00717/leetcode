#include <stack>
#include <string>
#include <unordered_map>
class Solution {
private:
  const std::unordered_map<char, char> bracketPairs = {
      {')', '('},
      {']', '['},
      {'}', '{'},
  };

public:
  bool isValid(const std::string &s) {
    std::stack<char> brackets;

    for (char ch : s) {
      if (bracketPairs.find(ch) == bracketPairs.end())
        brackets.push(ch);
      else {
        if (brackets.empty() || brackets.top() != bracketPairs.at(ch))
          return false;

        brackets.pop();
      }
    }

    return brackets.empty();
  }
};
