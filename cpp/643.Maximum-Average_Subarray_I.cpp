#include <algorithm>
#include <numeric>
#include <vector>
class Solution {
public:
  double findMaxAverage(std::vector<int> &nums, int k) {
    int l = 0, r = k-1, n = nums.size();
    int sum = std::accumulate(nums.begin(), nums.begin()+k, 0);
    int maxSum = sum;

    for (int i = k; i < n; i++) {
      sum -= nums[i-k];
      sum += nums[i];

      maxSum = std::max(maxSum, sum);
    }

    return (double)maxSum / k;
  }
};