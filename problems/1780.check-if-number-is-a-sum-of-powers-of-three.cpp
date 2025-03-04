/*
 * @lc app=leetcode id=1780 lang=cpp
 *
 * [1780] Check if Number is a Sum of Powers of Three
 */

// @lc code=start
class Solution {
private:
  bool dfs(int n) {
    if (n == 1)
      return true;
    if (n % 3 == 2)
      return false;

    if (n % 3 == 0)
      return dfs(n/3);
    else
      return dfs(n-1);
  }
public:
  bool checkPowersOfThree(int n) {
    return dfs(n);
  }
};
// @lc code=end
