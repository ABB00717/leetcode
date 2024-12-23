#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int result = 0;
    int last = -101;
    for (int i = 0; i < nums.size();) {
      if (last == nums[i]) {
        nums.erase(nums.begin()+i);
      } else {
        last = nums[i];
        result++;
        i++;
      }
    }

    return result;
  }
};
