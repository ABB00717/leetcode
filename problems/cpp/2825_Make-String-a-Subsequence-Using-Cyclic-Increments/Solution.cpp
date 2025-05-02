#include <string>
class Solution {
public:
  bool canMakeSubsequence(std::string str1, std::string str2) {
    int str1Index = 0, str2Index = 0;

    for (; str1Index < str1.size() && str2Index < str2.size(); str1Index++) {
      char current = str1[str1Index];
      char next = (current == 'z') ? 'a' : current + 1;

      if (str2[str2Index] == current || str2[str2Index] == next) {
        str2Index++;
      }

      if (str2Index == str2.size()) return true;
    }

    return str2Index == str2.size();
  }
};