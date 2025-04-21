/*
 * @lc app=leetcode id=2145 lang=cpp
 *
 * [2145] Count the Hidden Sequences
 */

// @lc code=start
#include <climits>
#include <vector>
class Solution {
public:
    int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
        long long current_sum = 0;
        long long max_val = 0;
        long long min_val = 0;
        
        for (const int& diff : differences) {
            current_sum += diff;
            max_val = std::max(max_val, current_sum);
            min_val = std::min(min_val, current_sum);
        }

        long range_min = lower - min_val;
        long range_max = upper - max_val;
        if (range_min > range_max) {
            return 0;
        }

        return (int)(range_max - range_min + 1);
    }
};
// @lc code=end