/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <cctype>
#include <cstddef>
#include <iostream>
#include <stack>
#include <string>
class Solution {
public:
  std::string decodeString(std::string s) {
    std::stack<int> multStack;
    std::stack<std::string> strStack;
    std::string result;
    int i = 0;

    while (i < s.size()) {
      if (std::isdigit(s[i])) {
        int mult = 0;

        while (std::isdigit(s[i])) {
          mult *= 10;
          mult += s[i++] - '0';
        }

        if (multStack.size() != strStack.size())
          strStack.push("");
        multStack.push(mult);

        // 因為變成了 [，要減回來
        i--;
      } else if (std::isalpha(s[i])) {
        std::string str;

        while (i < s.size() && std::isalpha(s[i])) {
          str += s[i++];
        }

        if (multStack.empty()) {
          result += str;
        } else if (multStack.size() == strStack.size()) {
          strStack.top() += str;
        } else {
          strStack.push(str);
        }

        i--;
      } else if (s[i] == ']') {
        std::string str;
        for (int i = 0; i < multStack.top(); i++) {
          str += strStack.top();
        }

        if (multStack.size() == 1) {
          result += str;
          multStack.pop();
          strStack.pop();
        } else {
          multStack.pop();
          strStack.pop();
          strStack.top() += str;
        }
      }

      i++;
    }

    return result;
  }
};
// @lc code=end
