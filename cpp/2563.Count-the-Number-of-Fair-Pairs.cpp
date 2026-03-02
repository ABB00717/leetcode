#include <algorithm>
#include <vector>

class Solution {
public:
  long long countFairPairs(std::vector<int> &nums, int lower, int upper) {
    long long result = 0;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      int l = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
      int r = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;

      result += std::max(0, r - l + 1);
    }

    return result;
  }
};
