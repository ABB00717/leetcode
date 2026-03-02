/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
#include <string>

class Solution {
   public:
    std::string pushDominoes(std::string dominoes) {
        int n = dominoes.size();

        std::string temp = 'L' + dominoes + 'R';
        int i = 0;
        for (int j = 1; j < temp.size(); j++) {
            if (temp[j] == '.')
                continue;

            if (temp[i] == 'L' && temp[j] == 'L') {
                for (int k = i; k < j - 1; k++)
                    dominoes[k] = 'L';
            } else if (temp[i] == 'R' && temp[j] == 'R') {
                for (int k = i; k < j - 1; k++)
                    dominoes[k] = 'R';
            } else if (temp[i] == 'R' && temp[j] == 'L') {
                int mid = (j - i - 1) / 2;
                for (int k = 0; k < mid; ++k) {
                    dominoes[i + k] = 'R';
                }
                for (int k = 0; k < mid; ++k) {
                    dominoes[j - 2 - k] = 'L';
                }
            }

            i = j;
        }

        return dominoes;
    }
};

// @lc code=end
