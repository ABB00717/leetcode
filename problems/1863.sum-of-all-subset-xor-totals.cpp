/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> subsets;
        int n = nums.size();

        // Generate all subsets
        std::vector<int> currentSubset;
        generateSubsets(nums, currentSubset, 0, subsets);

        int totalXORSum = 0;
        // Calculate the XOR sum of all subsets
        for (const auto& subset : subsets) {
            int xorSum = 0;
            for (int num : subset) {
                xorSum ^= num;
            }
            totalXORSum += xorSum;
        }

        return totalXORSum;
    }
private:
    void generateSubsets(std::vector<int>& nums, std::vector<int>& currentSubset, int index, std::vector<std::vector<int>>& subsets) {
        if (index == nums.size()) {
            subsets.push_back(currentSubset);
            return;
        }

        // Include the current element
        currentSubset.push_back(nums[index]);
        generateSubsets(nums, currentSubset, index + 1, subsets);

        // Exclude the current element
        currentSubset.pop_back();
        generateSubsets(nums, currentSubset, index + 1, subsets);
    }
};
// @lc code=end

