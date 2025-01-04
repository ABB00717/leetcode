#include <iostream>
#include <ostream>
#include <set>
#include <string>
class Solution {
public:
  int countPalindromicSubsequence(std::string s) {
    std::set<std::string> result;

    int l = 0;
    std::set<char> usedPrefix;
    while (l < s.size()) {
      usedPrefix.insert(s[l]);
      int r = s.size() - 1;
      while (l < r) {
        if (s[l] != s[r]) {
          r--;
          continue;
        }

        for (int i = l+1; i < r; i++) {
          std::string palindrom;
          palindrom += s[l];
          palindrom += s[i];
          palindrom += s[r];
          result.insert(palindrom);
        }
        break;
      }
      while (usedPrefix.find(s[l]) != usedPrefix.end())
        l++;
    }

    return result.size();
  }
};