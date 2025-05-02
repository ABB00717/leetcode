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
        std::string previous = dominoes;

        do {
            previous = dominoes;

            for (int i = 0; i < dominoes.size() - 1; i++) {
                if (dominoes[i] == '.' && dominoes[i + 1] == 'L')
                    dominoes[i] = 'l';
            }

            for (int i = dominoes.size() - 1; i > 0; i--) {
                if (dominoes[i] == '.' && dominoes[i - 1] == 'R')
                    dominoes[i] = 'R';
                else if (dominoes[i] == 'l' && dominoes[i - 1] == 'R')
                    dominoes[i] = '.';
                else if (dominoes[i] == 'l')
                    dominoes[i] = 'L';
            }
        } while (previous != dominoes);


        if (dominoes.size() == 1)
            return dominoes;
        
        if (dominoes[1] == 'L' && dominoes[0] == '.' || dominoes[0] == 'l')
            dominoes[0] = 'L';

        if (dominoes[dominoes.size() - 2] == 'R' && dominoes[dominoes.size() - 1] == '.' || dominoes[dominoes.size() - 1] == 'r')
            dominoes[dominoes.size() - 1] = 'R';

        return dominoes;
    }
};

// @lc code=end
