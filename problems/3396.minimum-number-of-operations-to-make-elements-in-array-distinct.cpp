/*
 * @lc app=leetcode id=3396 lang=cpp
 *
 * [3396] Minimum Number of Operations to Make Elements in Array Distinct
 */

// @lc code=start
#include <unordered_map>
#include <vector>
class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (const auto& num : nums) {
            m[num]++;
        }

        int operations = 0;
        while (nums.size() != m.size()) {
            operations++;
            for (int count = 0; count < 3 && !nums.empty(); count++) {
                int num = nums.front();
                nums.erase(nums.begin());
                if (m[num] > 1) {
                    m[num]--;
                } else {
                    m.erase(num);
                }
            }
        }

        return operations;
    }
};
// @lc code=end

