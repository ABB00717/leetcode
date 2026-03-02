#include <string>

class Solution {
public:
  std::string makeFancyString(std::string s) {
    std::string result;
    result.push_back(s[0]);
    if (s.size() > 1) result.push_back(s[1]);

    for (int i = 2; i < s.size(); i++) {
      if (s[i] == s[i - 1] && s[i] == s[i - 2]) continue;
      result.push_back(s[i]);
    }

    return result;
  }
};
