#include <iostream>
#include <iterator>
#include <string>
#include <vector>
class Solution {
private:
  char rotate(char ch, const int diff) {
    int newPos = (ch - 'a' + diff) % 26;
    if (newPos < 0) newPos += 26;
    return newPos + 'a';
  }
public:
  std::string shiftingLetters(std::string s, std::vector<std::vector<int>> &shifts) {
    int n = s.size();
    std::vector<int> totalShifts(n+1, 0);

    for (auto &shift : shifts) {
      int diff = (shift[2] == 1 ? 1 : -1);
      totalShifts[shift[0]] += diff;
      if (shift[1] + 1 < n) {
        totalShifts[shift[1] + 1] -= diff;
      }
    }

    int curDiff = 0;
    for (int i = 0; i < n; i++) {
      curDiff += totalShifts[i];
      s[i] = rotate(s[i], curDiff);
    }

    return s;
  }
};