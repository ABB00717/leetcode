/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
public:
  int numberOfSubstrings(std::string s) {
    int l = 0, r = 0, result = 0, n = s.size();
    std::vector<int> count(3, 0);

    while (r < n) {
      count[s[r]-'a']++;

      while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
        result += n - r;

        count[s[l]-'a']--;
        l++;
      }

      r++;
    }
    
    return result;
  }
};
// @lc code=end
