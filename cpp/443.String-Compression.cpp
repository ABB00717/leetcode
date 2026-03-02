#include <string>
#include <vector>
class Solution {
public:
  int compress(std::vector<char> &chars) {
    int n = chars.size();
    std::string result;
    char groupHead = chars[0];
    int groupLen = 1;

    for (int i = 1; i < n; i++) {
      if (chars[i] == groupHead) {
        groupLen++;
      } else {
        result += groupHead;
        if (groupLen > 1)
          result += std::to_string(groupLen);
        groupHead = chars[i];
        groupLen = 1;
      }
    }

    result += groupHead;
    if (groupLen > 1)
      result += std::to_string(groupLen);

    std::vector<char> newChars(result.begin(), result.end());
    chars = newChars;

    return result.size();
  }
};