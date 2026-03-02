/*
 * @lc app=leetcode id=2033 lang=cpp
 *
 * [2033] Minimum Operations to Make a Uni-Value Grid
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <vector>
class Solution {
   public:
    int minOperations(std::vector<std::vector<int>>& grid, int x) {
        std::vector<int> elements;
        elements.reserve(grid.size() * grid[0].size());
        for (const auto& row : grid) {
            elements.insert(elements.end(), row.begin(), row.end());
        }

        std::sort(elements.begin(), elements.end(), std::less<int>());

        int mid = elements[static_cast<int>(elements.size()/2)];
        int prev = elements[0], totalSection = abs(mid - elements[0]) / x;
        for (int i = 1; i < elements.size(); i++) {
            int mod = (elements[i] - prev) % x;
            if (mod != 0)
                return -1;

            totalSection += abs(mid - elements[i]) / x;
            prev = elements[i];
        }
        
        return totalSection;
    }
};

// @lc code=end
