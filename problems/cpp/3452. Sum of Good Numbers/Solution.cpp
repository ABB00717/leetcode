#include <vector>
class Solution {
public:
  int sumOfGoodNumbers(std::vector<int> &nums, int k) {
    int result = 0;

    for (int i = 0; i < nums.size(); i++) {
      int low = i - k, high = i + k;
      
      if (low >= 0 && nums[low] >= nums[i]) continue;
      if (high < nums.size() && nums[high] >= nums[i]) continue;
      
      result += nums[i];
    }

    return result;
  }
};