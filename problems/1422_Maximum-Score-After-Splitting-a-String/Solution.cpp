#include <algorithm>
#include <string>
class Solution {
public:
  int maxScore(std::string s) {
    int zeroCount = 0, oneCount = 0;

    for (char number : s) {
      if (number == '1') oneCount++;
    }

    int result = 0;
    for (int i = 0; i < s.size()-1; i++) {
      if (s[i] == '0') zeroCount++;
      else oneCount--;

      result = std::max(result, oneCount + zeroCount);
    }

    return result;
  }
};
