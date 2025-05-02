#include <csetjmp>
#include <unordered_map>
#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int n = nums.size();
    int stable = 0;
    std::unordered_map<int, int> count;

    for (int i = 0; i < nums.size(); i++) {
      count[nums[i]]++;
      if (count[nums[i]] < 3) {
        nums[stable] = nums[i];
        stable++;
      }
    }

    return stable + 1;
  }
};