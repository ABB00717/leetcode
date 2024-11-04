#include <string>

class Solution {
public:
  std::string compressedString(std::string word) {
    std::string result = "";
    char cur = word[0];
    int count = 1;

    for (int i = 1; i < word.length(); i++) {
      if (cur != word[i] || count == 9) {
        result += (std::to_string(count) + cur);
        cur = word[i];
        count = 1;
      } else {
        count++;
      }
    }

    result += (std::to_string(count) + cur);
    return result;
  }
};