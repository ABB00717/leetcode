#include <numeric>
#include <vector>
class Solution {
public:
  int pivotIndex(std::vector<int> &nums) {
    if (nums.size() < 2)
      return -1;
    int lSum = 0, rSum = std::accumulate(nums.begin(), nums.end(), 0);

    for (int div = 0; div < nums.size(); div++) {
      rSum -= nums[div];
      if (lSum == rSum)
        return div;
      lSum += nums[div];
    }

    return -1;
  }
};