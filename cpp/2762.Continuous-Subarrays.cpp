#include <algorithm>
#include <deque>
#include <vector>

class Solution {
public:
  long long continuousSubarrays(std::vector<int> &nums) {
    long long result = 0;
    int left = 0;             // 左指針
    std::deque<int> maxDeque; // 儲存最大值的 index
    std::deque<int> minDeque; // 儲存最小值的 index

    for (int right = 0; right < nums.size(); ++right) {
      // 更新最大值的 deque
      while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
        maxDeque.pop_back();
      }
      maxDeque.push_back(right);

      // 更新最小值的 deque
      while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
        minDeque.pop_back();
      }
      minDeque.push_back(right);

      // 檢查窗口是否合法
      while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
        if (maxDeque.front() == left)
          maxDeque.pop_front();
        if (minDeque.front() == left)
          minDeque.pop_front();
        ++left; // 縮小左邊界
      }

      // 計算當前窗口的子陣列數量
      result += (right - left + 1);
    }

    return result;
  }
};
