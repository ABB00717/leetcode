#include <string>
#include <vector>
class Solution {
public:
  int prefixCount(std::vector<std::string> &words, std::string pref) {
    int result = 0;

    for (auto word : words) {
      if (word.find(pref) == 0) result++;
    }

    return result;
  }
};