#include <numeric>
#include <vector>
class Solution {
public:
  int pivotIndex(std::vector<int> &nums) {
    long long totalSum = std::accumulate(nums.begin(), nums.end(), 0);
    long long leftSum = 0;

    for (int div = 0; div < nums.size(); div++) {
      if (leftSum == totalSum - leftSum - nums[div]) {
        return div;
      }

      leftSum += nums[div];
    }
    
    return -1;
  }
};