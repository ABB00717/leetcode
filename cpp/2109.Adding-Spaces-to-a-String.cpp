#include <string>
#include <vector>

class Solution {
public:
  std::string addSpaces(std::string s, std::vector<int> &spaces) {
    std::string result;
    result.reserve(s.size() + spaces.size());

    int spaceIndex = 0;
    for (int i = 0; i < s.size(); i++) {
      if (spaceIndex < spaces.size() && spaces[spaceIndex] == i) {
        result.push_back(' ');
        spaceIndex++;
      }

      result.push_back(s[i]);
    }

    return result;
  }
};