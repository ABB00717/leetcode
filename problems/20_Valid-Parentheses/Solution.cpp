#include <stack>
#include <string>
#include <vector>

class Solution {
private:
  enum bracketType { Open, Close };
  const std::vector<std::vector<char>> pairs = {
      {'[', ']'}, {'{', '}'}, {'(', ')'}};

  int findBracketType(char bracket) {
    for (const auto &pair : pairs) {
      if (bracket == pair[Open])
        return Open;
      if (bracket == pair[Close])
        return Close;
    }

    return Close;
  }
  int findBracket(char bracket, bracketType type) {
    for (int i = 0; i < pairs.size(); i++) {
      if (bracket == pairs[i][type])
        return i;
    }

    return -1;
  }

public:
  bool isValid(std::string s) {
    std::stack<char> brackets;

    for (auto ch : s) {
      if (findBracketType(ch) == Open) {
        brackets.push(ch);
      } else {
        if (brackets.empty() ||
            brackets.top() != pairs[findBracket(ch, Close)][Open])
          return false;

        brackets.pop();
      }
    }

    return brackets.empty();
  }
};
