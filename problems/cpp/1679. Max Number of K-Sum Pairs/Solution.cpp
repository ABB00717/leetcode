#include <algorithm>
#include <functional>
#include <vector>
class Solution {
public:
  int maxOperations(std::vector<int> &nums, int k) {
    int result = 0;
    std::sort(nums.begin(), nums.end(), std::less<int>());

    int l = 0, r = nums.size()-1;
    while (l < r) {
      if (nums[l] + nums[r] < k) {
        l++;
      } else if (nums[l] + nums[r] > k) {
        r--;
      } else if (nums[l] + nums[r] == k) {
        l++;
        r--;
        result++;
      }
    }

    return result;
  }
};