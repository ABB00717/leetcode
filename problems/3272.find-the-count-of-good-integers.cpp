/*
 * @lc app=leetcode id=3272 lang=cpp
 *
 * [3272] Find the Count of Good Integers
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>

class Solution {
   private:
    long long calculate_valid_permutations(const std::vector<int>& counts,
                                           int n) {
        // permutatiols = n! / (c0! * c1! * ... * c9!)
        long long total_perms_numerator = factorial(n);
        long long denominator = 1;
        for (int count : counts) {
            denominator *= factorial(count);
        }

        long long total_perms = total_perms_numerator / denominator;

        // if '0' exists and the number of digits is greater than 1, we need to subtract the permutations starting with '0'
        if (counts[0] > 0 && n > 1) {
            // permutations starting with '0' = (n-1)! / ((c0-1)! * c1! * ... * c9!)
            long long zero_start_perms_numerator = factorial(n - 1);
            long long zero_start_denominator = 1;
            for (int i = 0; i < 10; ++i) {
                int count = counts[i];
                if (i == 0) {
                    // for '0', we reduce the count by 1
                    count--;
                }
                // ensure count is not negative (though theoretically it shouldn't be)
                zero_start_denominator *= factorial(count >= 0 ? count : 0);
            }

            long long zero_start_perms =
                zero_start_perms_numerator / zero_start_denominator;
            total_perms -= zero_start_perms; // subtract invalid permutations
        }

        return total_perms;
    }

    long long factorial(int n) {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

   public:
    long long countGoodIntegers(int n, int k) {
        long long total_good_integers = 0;
        // using a set to store unique signatures to avoid duplicates
        std::set<std::vector<int>> processed_signatures;

        int half_len = (n + 1) / 2;
        long long start =
            (half_len == 1) ? 1 : (long long)std::pow(10, half_len - 1);
        long long end = (long long)std::pow(10, half_len);

        for (long long i = start; i < end; i++) {
            std::string first_half_str = std::to_string(i);
            std::string second_half_str = first_half_str;

            // if n is odd, we need to remove the last digit from the second half
            if (n % 2 == 1 && !second_half_str.empty()) {
                second_half_str.pop_back();
            }
            std::reverse(second_half_str.begin(), second_half_str.end());

            // create the full palindromic string
            std::string palin_str = first_half_str + second_half_str;

            long long palin_num = std::stoll(palin_str);

            // check if the palindromic number is divisible by k
            if (palin_num % k != 0)
                continue;

            // calculate the digit counts
            std::vector<int> digit_counts(10, 0);
            for (char c : palin_str) {
                digit_counts[c - '0']++;
            }

            if (processed_signatures.insert(digit_counts).second) {
                long long valid_perms =
                    calculate_valid_permutations(digit_counts, n);
                total_good_integers += valid_perms;
            }
        }

        return total_good_integers;
    }
};

// @lc code=end
