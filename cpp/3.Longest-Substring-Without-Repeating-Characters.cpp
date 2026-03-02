#include <string>
#include <unordered_map>
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int l = 0, r = 0, max = 0;
    std::unordered_map<char, bool> count;

    while (r < s.size()) {
      if (count.find(s[r]) == count.end() || !count[s[r]]) {
        count[s[r]] = true;
        r++;
        max = std::max(max, r - l);
      } else {
        count[s[l]] = false;
        l++;
      }
    }

    return max;
  }
};
