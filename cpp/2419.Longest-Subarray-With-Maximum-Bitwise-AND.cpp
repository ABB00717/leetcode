#include <algorithm>
#include <vector>
class Solution {
public:
  int longestSubarray(std::vector<int> &nums) {
    int largest = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > largest) {
        largest = nums[i];
      }
    }

    int largestBit = 1, l = 0, r = 0;
    while (l < nums.size()) {
      if (nums[l] != largest) {
        r = ++l;
      } else {
        while (r < nums.size() && nums[r] == largest) {
          r++;
        }
        largestBit = std::max(largestBit, r - l);
        l = r;
      }
    }

    return largestBit;
  }
};