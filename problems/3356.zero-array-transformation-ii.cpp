/*
 * @lc app=leetcode id=3356 lang=cpp
 *
 * [3356] Zero Array Transformation II
 */

// @lc code=start
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
class Solution {
public:
  int minZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries) {
    std::vector<int> prefixSum(nums.size()+1, 0);
    for (const auto& query : queries) {
      prefixSum[query[0]] += query[2];
      prefixSum[query[1]+1] -= query[2];
    }

    int cur = 0;
    bool allZero = true;
    for (int i = 0; i < nums.size(); i++) {
      cur += prefixSum[i];
      if (nums[i] - cur > 0)
        return -1;
      if (nums[i] != 0)
        allZero = false;
    }

    if (allZero)
      return 0;

    int l = 0, h = queries.size()-1;
    while (l < h) {
      int k = (l + h) / 2;
      prefixSum.assign(nums.size()+1, 0);

      for (int i = 0; i <= k; i++) {
        prefixSum[queries[i][0]] += queries[i][2];
        prefixSum[queries[i][1]+1] -= queries[i][2];
      }
      
      int i = 0, cur = 0;
      for (i = 0; i < nums.size(); i++) {
        cur += prefixSum[i];
        if (nums[i] - cur > 0) {
          l = k + 1;
          break;
        }
      }
      
      if (i == nums.size())
        h = k;
    }
    
    return l == queries.size() ? -1 : l + 1;
  }
};
// @lc code=end
