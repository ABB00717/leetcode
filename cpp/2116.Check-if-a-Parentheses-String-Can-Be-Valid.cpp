#include <stack>
#include <string>
class Solution {
public:
  bool canBeValid(std::string s, std::string locked) {
    int n = s.size();
    if (n % 2)
      return false;

    /* 左括號
      * low: 當前位置可能有的最小左括號數量
      * high: 當前位置可能有的最大左括號數量
    */
    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
      if (locked[i] == '0') {
        low--;
        high++;
      } else if (s[i] == '(') {
        low++;
        high++;
      } else {
        low--;
        high--;
      }

      if (high < 0)
        return false;
      low = std::max(0, low);
    }

    // 右括號
    low = 0, high = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (locked[i] == '0') {
        low--;
        high++;
      } else if (s[i] == ')') {
        low++;
        high++;
      } else {
        low--;
        high--;
      }

      if (high < 0)
        return false;
      low = std::max(0, low);
    }

    return true;
  }
};
