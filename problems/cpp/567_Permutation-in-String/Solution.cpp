#include <string>
#include <unordered_map>

class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    if (s1.size() > s2.size())
      return false;

    std::unordered_map<char, int> characters;
    for (auto c : s1) {
      characters[c]++;
    }

    int l = 0, r = 0, required = s1.size();
    while (r < s2.size()) {
      if (characters.find(s2[r]) != characters.end()) {
        if (characters[s2[r]] > 0)
          required--;
        characters[s2[r]]--;
      }

      if (r - l + 1 > s1.size()) {
        if (characters.find(s2[l]) != characters.end()) {
          if (characters[s2[l]] >= 0) 
            required++;
          characters[s2[l]]++;
        }
        l++;
      }

      if (required == 0)
        return true;
      r++;
    }

    return false;
  }
};