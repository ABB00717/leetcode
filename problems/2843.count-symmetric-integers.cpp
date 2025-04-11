/*
 * @lc app=leetcode id=2843 lang=cpp
 *
 * [2843]   Count Symmetric Integers
 */

// @lc code=start
#include <iostream>
#include <string>
class Solution {
   public:
    int countSymmetricIntegers(int low, int high) {
        int number_of_symmetric_integers = 0;
        
        for (int current = low; current <= high; current++) {
            std::string num_str = std::to_string(current);
            if (num_str.size() % 2 == 1 ) {
                continue;
            }

            int first_sum = 0, last_sum = 0;
            for (int i = 0; i < num_str.size() / 2; i++) {
                first_sum += num_str[i] - '0';
                last_sum += num_str[num_str.size() - 1 - i] - '0';
            }

            if (first_sum == last_sum) {
                number_of_symmetric_integers++;
            }
        }

        return number_of_symmetric_integers;
    }
};

// @lc code=end
