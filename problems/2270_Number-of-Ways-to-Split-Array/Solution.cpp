#include <vector>
class Solution {
public:
  int waysToSplitArray(std::vector<int> &nums) {
    int result = 0;
    long long int left = 0, right = 0;
    for (int num : nums) {
      right += num;
    }

    for (int i = 0; i < nums.size()-1; i++) {
      left += nums[i];
      right -= nums[i];
      if (left >= right) result++;
    }

    return result;
  }
};