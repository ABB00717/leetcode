#include <string>

class Solution {
public:
  std::string makeFancyString(std::string s) {
    std::string result;
    char prev = '\0';
    int countPrev = 0;

    for (char ch : s) {
      if (ch != prev) {
        prev = ch;
        countPrev = 1;
      } else {
        countPrev++;
        if (countPrev > 2) continue;
      }

      result.push_back(ch);
    }

    return result;
  }
};
