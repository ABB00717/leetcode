#include <stack>
#include <string>
class Solution {
public:
  std::string removeStars(std::string s) {
    std::string result;
    result.reserve(s.size());

    for (const char& ch : s) {
      if (ch == '*') {
        if (!result.empty())
          result.pop_back();
      } else {
        result.push_back(ch);
      }
    }

    return result;
  }
};