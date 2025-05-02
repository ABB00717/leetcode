/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
#include <string>
class Solution {
   public:
    std::string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        std::string prevString = countAndSay(n - 1);
        std::string result;
        char prevChar = prevString[0];
        int count = 1;
        for (int i = 1; i <= prevString.size(); i++)  {
            if (i == prevString.size()) {
                result += std::to_string(count) + prevChar;
            } else if (prevString[i] == prevChar) {
                count++;
            } else {
                result += std::to_string(count) + prevChar;
                prevChar = prevString[i];
                count = 1;
            }
        }
        
        return result;
    }
};

// @lc code=end
