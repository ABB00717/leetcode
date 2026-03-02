/*
 * @lc app=leetcode id=3394 lang=cpp
 *
 * [3394] Check if Grid can be Cut into Sections
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
   public:
    bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles) {
        std::vector<std::pair<int, int>> xCors, yCors;

        for (const auto& rect : rectangles) {
            xCors.emplace_back(rect[0], rect[2]);
            yCors.emplace_back(rect[1], rect[3]);
        }

        std::sort(xCors.begin(), xCors.end());
        std::sort(yCors.begin(), yCors.end());

        bool xValid = isCorValid(xCors);
        bool yValid = isCorValid(yCors);

        return xValid || yValid;
    }

   private:
    bool isCorValid(const std::vector<std::pair<int, int>>& cors) {
        int farthest = 0, divide = 0;
        for (int i = 0; i < cors.size() - 1; i++) {
            farthest = std::max(farthest, cors[i].second);

            // If the farthest right endpoint so far doesn't reach the start of the next interval
            // it means we can make a clean cut here
            if (farthest <= cors[i + 1].first) {
                divide++;
            }

            if (divide == 2) {
                return true;
            }
        }

        return false;
    }
};

// @lc code=end
