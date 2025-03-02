#include <algorithm>
#include <vector>
class Solution {
public:
  int longestOnes(std::vector<int> &nums, int k) {
    int l = 0, r = 0, zeroNum = 0;
    int maxLen = 0;

    while (r < nums.size()) {
      if (nums[r] == 0)
        zeroNum++;

      if (zeroNum <= k) {
        r++;
      } else if (zeroNum > k) {
        maxLen = std::max(maxLen, r - l);
        while (nums[l] == 1 && l < nums.size()) {
          l++;
        }
        l++;
        r++;
        zeroNum--;
      }
    } 

    maxLen = std::max(maxLen, r - l);

    return maxLen;
  }
};