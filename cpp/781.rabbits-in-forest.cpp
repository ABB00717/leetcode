/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */

// @lc code=start
#include <unordered_map>
#include <vector>
class Solution {
   public:
    int numRabbits(std::vector<int>& answers) {
        int rabbits = 0;
        std::unordered_map<int, int> color_count;
        for (const int& answer : answers) {
            color_count[answer]++;
        }

        for (const auto& [answer, count] : color_count) {
            int group_size = answer + 1;
            int groups = (count + group_size - 1) / group_size;  // ceil(count / group_size)
            rabbits += groups * group_size;
        }

        return rabbits;
    }
};

// @lc code=end
