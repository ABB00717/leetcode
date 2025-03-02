#include <vector>
class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    int countZero = 0;
    for (int num : nums) {
      if (num == 0)
        countZero++;
    }

    for (int i = nums.size()-1; i >= 0 && nums[i] == 0; i--) {
      countZero--;
    }

    int i = 0;
    while (countZero > 0) {
      if (nums[i] == 0) {
        nums.erase(nums.begin() + i);
        nums.push_back(0);
        countZero--;
      } else {
        i++;
      }
    }
  }
};