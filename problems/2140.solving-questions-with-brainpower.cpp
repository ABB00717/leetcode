/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    /*
    Maximize the total points by deciding whether to solve or skip each question.
    Strategy:
    - Use bottom-up dynamic programming (from last question to first).
    - dp[i] = the maximum points we can get starting from question i.
    - For each question i:
        Option 1: Solve it -> gain points[i], then skip brainpower[i] questions
        Option 2: Skip it -> take dp[i+1] (already computed from previous iteration).
    */
    long long mostPoints(std::vector<std::vector<int>>& questions) {
        int n = questions.size();
        // dpc[i] stores the maximum points achievable starting from question i
        std::vector<long long> dp(n, 0);

        // Stores the global max while iterating backwards
        long long result = 0;
        for (int i = n-1; i >= 0; i--) {
            // Start with the points from solving question i
            long long curMax = questions[i][0];
            // The next available question index after skipping 
            int next = questions[i][1] + i + 1;
            // If we can continue after skipping brainpower[i] questions
            if (next < n) {
                // Add the optimal points we can get from that future point
                curMax += dp[next]; 
            }

            // Compare current plan (solve question i) vs previous best (skip question i)
            result = std::max(curMax, result);
            // Store the best result starting from i
            dp[i] = result;
        }

        return result;
    }
};
