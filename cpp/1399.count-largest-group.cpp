/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */

// @lc code=start
#include <unordered_map>
class Solution {
   public:
    int countLargestGroup(int n) {
        std::unordered_map<int, int> group_count;

        int max_group_size = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            int num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            group_count[sum]++;
            max_group_size = std::max(max_group_size, group_count[sum]);
        }

        int largest_group_count = 0;
        for (const auto& pair : group_count) {
            if (pair.second == max_group_size) {
                largest_group_count++;
            }
        }

        return largest_group_count;
    }
};

// @lc code=end
