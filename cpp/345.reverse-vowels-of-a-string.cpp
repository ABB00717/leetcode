/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#include <unordered_set>
#include <utility>
#include <vector>
class Solution {
private:
  const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  bool isVowel(const char& ch) {
    return vowels.count(ch);
  }
  
public:
  string reverseVowels(string s) {
    int l = 0, r = s.size();

    while (l <= r) {
      if (!isVowel(s[l]))
        l++;
      else if (!isVowel(s[r]))
        r--;
      else
        std::swap(s[l++], s[r--]);
    }
    
    return s;
  }
};
// @lc code=end
