#include <string>

class Solution {
public:
  int minChanges(std::string s) {
    if (s.size() % 2 == 1) return 0;

    int count = 0;
    char odd;
    for (int i = 0; i < s.length(); i++) {
      if (i % 2 == 0) {
        odd = s[i];
      } else {
        if (odd != s[i]) count++;
      }
    }

    return count;
  }
};