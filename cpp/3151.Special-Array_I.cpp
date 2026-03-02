#include <vector>
class Solution {
public:
  bool isArraySpecial(std::vector<int> &nums) {
    bool odd = nums[0] % 2 == 1;

    for (int i = 1; i < nums.size(); i++) {
      if (odd == nums[i] % 2 == 1) {
        return false;
      }

      odd = !odd;
    }

    return true;
  }
};