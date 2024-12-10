#include <algorithm>
#include <string>
#include <vector>

const int MAX_LENGTH = 50;

class Solution {
public:
  int maximumLength(std::string s) {
    std::vector<std::vector<int>> chMaps(26, std::vector<int>(s.size() + 1, 0));
    int result = 0;

    int countCur = 1;
    char cur = s[0];
    for (int i = 1; i <= s.size(); i++) {
      if (i != s.size() && s[i] == cur) {
        countCur++;
        continue;
      }

      int minSize = countCur - 2;
      for (int add = 3; add > 0; add--) {
        chMaps[cur - 'a'][std::max(minSize + (3 - add), 0)] += add;
      }

      if (i != s.size())
        cur = s[i];
      countCur = 1;
    }

    for (auto chMap : chMaps) {
      for (int i = 0; i < s.size(); i++) {
        if (chMap[i] >= 3)
          result = std::max(result, i);
      }
    }

    return result == 0 ? -1 : result;
  }
};
