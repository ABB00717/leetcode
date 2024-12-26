#include <unordered_map>
#include <vector>
class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    std::unordered_map<int, int> count;
    int majority = static_cast<int>(nums.size() / 2);

    for (auto num : nums) {
      count[num]++;
      if (count[num] > majority) {
        return  num;
      }
    }

    return 0;
  }
};
