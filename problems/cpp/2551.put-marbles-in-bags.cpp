/*
 * @lc app=leetcode id=2551 lang=cpp
 *
 * [2551] Put Marbles in Bags
 */

// @lc code=start
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <vector>
class Solution {
public:
    // Given an array of marble weight, and a requirement to divide them into k bags,
    // we aim to maximize and minimize the total "score" based on where the partitions happen.Solution

    // Each partition is placed between two marbles(i.e., between weights[i] and weights[i+1]),
    // and contributes weights[i] + weights[i+1] to the score.Solution

    // The goal is to compute the difference between the maximum and minimum possible scores,
    // by selecting the (k-1) most valuable and least valuable partition points.
    long long putMarbles(std::vector<int>& weights, int k) {
        int n = weights.size();

        // Store the sum of adjacent marble pairs, which represent partition "costs"
        std::vector<int> pairSums;
        for (int i = 0; i < n-1; i++) {
            pairSums.push_back(weights[i] + weights[i+1]);
        }

        // Sort the partition costs in descending order
        std::sort(pairSums.begin(), pairSums.end(), std::greater<int>());

        // Accumulate the top (k-1) largest and smallest partition values
        long long max = 0, min = 0;
        for (int i = 0; i < (k-1); i++) {
            max += pairSums[i];
            min += pairSums[pairSums.size()-1-i];
        }

        return max - min;
    }
};
// @lc code=end

