/*
 * @lc app=leetcode id=3356 lang=cpp
 *
 * [3356] Zero Array Transformation II
 */

// @lc code=start
#include <algorithm>
#include <cstdlib>
#include <vector>
class Solution {
public:
  int minZeroArray(std::vector<int> &nums,
                   std::vector<std::vector<int>> &queries) {
    std::vector<int> diffs(nums.size() + 1, 0);
    accumulateToK(queries, diffs, queries.size() - 1);

    if (!isValid(nums, diffs))
      return -1;
    if (isAllZero(nums))
      return 0;

    int l = 0, h = queries.size() - 1;
    int answer = -1;

    while (l <= h) {
      int k = l + (h - l) / 2;

      diffs.assign(nums.size() + 1, 0);
      accumulateToK(queries, diffs, k);

      if (isValid(nums, diffs)) {
        h = k - 1;
        answer = k + 1;
      } else {
        l = k + 1;
      }
    }

    return answer;
  }

private:
  void accumulateToK(const std::vector<std::vector<int>> &queries,
                     std::vector<int> &diffs, int k) {
    for (int i = 0; i <= k; i++) {
      diffs[queries[i][0]] += queries[i][2];
      diffs[queries[i][1] + 1] -= queries[i][2];
    }
  }

  bool isValid(const std::vector<int> &nums, const std::vector<int> &diffs) {
    int cur = 0;
    for (int i = 0; i < nums.size(); i++) {
      cur += diffs[i];
      if (nums[i] - cur > 0)
        return false;
    }

    return true;
  }

  bool isAllZero(const std::vector<int> &nums) {
    return std::all_of(nums.begin(), nums.end(),
                       [](int num) { return num == 0; });
  }
};
// @lc code=end
