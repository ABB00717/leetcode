#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int count = 0;
    int prev = -10001;

    for (int i = 0; i < nums.size();i++) {
      if (prev == nums[i]) {
        count++;
        if (count >= 2) {
          nums.erase(nums.begin()+i);
          i--;
        }
        continue;
      }

      prev = nums[i];
      count = 1;
    }

    return nums.size();
  }
};