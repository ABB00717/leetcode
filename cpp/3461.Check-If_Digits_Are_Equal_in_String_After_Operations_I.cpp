#include <string>
class Solution {
public:
  bool hasSameDigits(std::string s) {
    int n = s.size();
    std::string twoDigits = s;

    while (twoDigits.size() > 2) {
      std::string newTwoDigits(n - 1, '0');
      for (int i = 0; i < n - 1; i++) {
        newTwoDigits[i] =
            (twoDigits[i] - '0' + twoDigits[i + 1] - '0') % 10 + '0';
      }
      twoDigits = newTwoDigits;
      n--;
    }

    return twoDigits[0] == twoDigits[1];
  }
};