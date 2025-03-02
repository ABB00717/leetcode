#include <algorithm>
#include <string>
#include <vector>
class Solution {
private:
  const std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  bool isVowel(char ch) {
    for (char vowel : vowels) {
      if (ch == vowel)
        return true;
    }

    return false;
  }
public:
  int maxVowels(std::string s, int k) {
    int vowelNum = 0;
    for (int i = 0; i < k; i++) {
      if (isVowel(s[i])) {
        vowelNum++;
      }
    }

    int maxVowelNum = vowelNum;
    for (int i = k; i < s.size(); i++) {
      if (isVowel(s[i])) {
        vowelNum++;
      }
      if (isVowel(s[i-k])) {
        vowelNum--;
      }

      maxVowelNum = std::max(maxVowelNum, vowelNum);
    }

    return maxVowelNum;
  }
};