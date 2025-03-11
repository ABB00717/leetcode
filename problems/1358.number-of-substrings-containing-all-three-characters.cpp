/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
#include <string>
#include <unordered_map>
class Solution {
public:
  int numberOfSubstrings(std::string s) {
    int l = 0, r = -1, result = 0, n = s.size();
    std::unordered_map<char, int> fq;

    for (r = -1; r < n && fq.size() < 3; r++) {
      fq[s[r+1]]++;
    }

    if (r == n)
      return 0;

    while (l < n) {
      for (;r < n && fq.size() < 3; r++) {
        fq[s[r+1]]++;
      }

      if (r < n) {
        result += (n - r);
      } else {
        break;
      }
      
      char lLetter = s[l];
      fq[lLetter]--;
      if (fq[lLetter] == 0) {
        fq.erase(lLetter);
      } 
      l++;
    }

    return result;
  }
};
// @lc code=end
