#include <algorithm>
#include <vector>
class Solution {
public:
  int longestSubarray(std::vector<int> &nums) {
    int left = 0, zeroCount = 0;
    int maxLen = 0;

    for (int right = 0; right < nums.size(); right++) {
      if (nums[right] == 0) {
        zeroCount++;
      }

      while (zeroCount > 1) {
        if (nums[left] == 0) {
          zeroCount--;
        }
        left++;
      }

      maxLen = std::max(maxLen, right - left);
    }

    return maxLen;
  }
};