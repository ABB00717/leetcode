#include <algorithm>
#include <functional>
#include <vector>
class Solution {
public:
  /*
  1. 只要知道最多能符合多少區間
  2. 區間是固定的

  先把 nums 排序，而因為是由大到小，因此可以用雙指針找。
  從最大的 right 開始，把 left 逼到範圍極限值之後，把 right 往左移動一格，之後再次試著移動 left，就這樣周而復始直到 right = -1。
  在過程中只要有持續比較 right - left，最後就能夠得到最大值了。
  */
  int maximumBeauty(std::vector<int> &nums, int k) {
    int result = 0;

    std::sort(nums.begin(), nums.end(), std::less<int>());
    
    int left = nums.size()-1;
    for (int right = nums.size()-1; right >= 0; right--) {
      while (left >= 0 && nums[right] - nums[left] <= 2*k) left--;

      result = std::max(result, right - left);
    }

    return result;
  }
};