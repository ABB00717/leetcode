#include <algorithm>
#include <utility>
#include <vector>
class Solution {
public:
  // 牛逼啊，三段反轉
  void rotate(std::vector<int> &nums, int k) {
    k = k % nums.size();

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin()+k);
    std::reverse(nums.begin()+k, nums.end());
  }
};
