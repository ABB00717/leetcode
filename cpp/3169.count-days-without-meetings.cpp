/*
 * @lc app=leetcode id=3169 lang=cpp
 *
 * [3169] Count Days Without Meetings
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
class Solution {
   public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        std::vector<std::pair<int, int>> events;

        for (const auto& m : meetings) {
            events.emplace_back(m[0], 1);
            events.emplace_back(m[1] + 1, -1);
        }

        std::sort(events.begin(), events.end());

        int result = 0;
        int cur = 0;
        int prev_day = 1;

        for (auto& e : events) {
            int day = e.first;

            if (cur == 0 && prev_day < day) {
                result += day - prev_day;
            }

            cur += e.second;
            prev_day = day;
        }

        if (cur == 0 && prev_day <= days) {
            result += days - prev_day + 1;
        }
        
        return result;
    }
};

// @lc code=end
