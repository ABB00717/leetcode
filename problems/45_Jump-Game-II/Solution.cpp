#include <algorithm>
#include <vector>
class Solution {
public:
  /*到每格都看能不能比之前還要遠，如果可以就先紀錄下來，不要跳。
    等到了理想中的最遠格子時，再跳。反正一定到的了終點，所以不用擔心*/
  int jump(std::vector<int> &nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int jumps = 0, end = 0, farthest = 0;
    for (int i = 0; i < n-1; i++) {
      farthest = std::max(farthest, i + nums[i]);

      if (i == end) {
        jumps++;
        end = farthest;
        if (end >= n - 1) break;
      }
    }

    return jumps;
  }
};