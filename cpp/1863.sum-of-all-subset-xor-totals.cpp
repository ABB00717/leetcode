/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
#include <vector>
#include <cmath> // Conceptually related to powers of 2, though not used directly

class Solution {
public:
    /**
     * @brief Calculates the sum of XOR totals for all subsets.
     *
     * This solution avoids iterating through all subsets by using a bit manipulation trick
     * to analyze the contribution of each bit.
     *
     * @param nums The input vector of integers.
     * @return The sum of XOR totals of all subsets.
     */
    int subsetXORSum(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        // Calculate the bitwise OR of all numbers.
        // orResult represents all the bit positions where at least one number in nums has a 1.
        int orResult = 0;
        for (int num : nums) {
            orResult |= num;
        }

        // Key concept:
        // For each bit k that is 1 in orResult, exactly 2^(n-1) subsets will have their XOR sum's k-th bit as 1.
        // Calculate 2 raised to the power of (n-1).
        int subsets_with_bit_set = (1 << (n - 1)); // Equivalent to pow(2, n - 1)

        // Final result: The sum of XOR totals of all subsets is orResult * 2^(n-1).
        return orResult * subsets_with_bit_set;
    }
};

// @lc code=end