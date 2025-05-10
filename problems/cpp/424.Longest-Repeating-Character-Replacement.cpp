#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    std::unordered_map<char, int> characters;
    int l = 0, maxCount = 0, windowSize = 0;

    for (int r = 0; r < s.size(); r++) {
      characters[s[r]]++;
      windowSize = r - l + 1;

      if (windowSize - std::max_element(characters.begin(), characters.end(),
                                        [](const auto &a, const auto &b) {
                                          return a.second < b.second;
                                        })
                           ->second >
          k) {
        characters[s[l]]--;
        l++;
      } else {
        maxCount = std::max(maxCount, windowSize);
      }
    }

    return maxCount;
  }
};