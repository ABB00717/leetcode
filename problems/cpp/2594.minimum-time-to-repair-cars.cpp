/*
 * @lc app=leetcode id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

class Solution {
   public:
    long long repairCars(std::vector<int>& ranks, int cars) {
        long long l = 0, r = *std::max_element(ranks.begin(), ranks.end()) *
                             (long long)cars * cars;

        long long minimum = LONG_LONG_MAX;
        while (l <= r) {
            long long m = l + (r - l) / 2;

            long long repairedCar = 0;
            for (const int& rank : ranks) {
                repairedCar += static_cast<long long>(std::sqrt(m / rank));
            }

            if (repairedCar >= cars) {
                minimum = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return minimum;
    }
};

// @lc code=end
