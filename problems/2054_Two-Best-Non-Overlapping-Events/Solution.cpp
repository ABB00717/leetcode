#include <algorithm>
#include <vector>

class Solution {
public:
  int maxTwoEvents(std::vector<std::vector<int>> &events) {
    int n = events.size();

    // 1. 將活動按開始時間進行排序，方便後續使用二分查找
    //    比較每個活動的開始時間 `a[0]` 和 `b[0]` 來確定排序順序
    std::sort(events.begin(), events.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[0] < b[0];
              });

    // 2. 初始化 suffMax，表示從當前活動開始到最後活動中價值的最大值
    //    suffMax[i] 表示從 i 開始向後的最大值
    std::vector<int> suffMax(n);
    suffMax[n - 1] = events[n - 1][2]; // 最後一個活動的最大值就是它本身
    for (int i = n - 2; i >= 0; i--)
      suffMax[i] = std::max(events[i][2], suffMax[i + 1]); // 動態更新最大值

    int maxSum = 0; // 用於存儲兩個互不重疊活動的最大價值和

    // 3. 遍歷每個活動，嘗試計算選擇該活動及其他非重疊活動的最大價值
    for (int i = 0; i < n; i++) {
      // 單獨選擇當前活動的價值
      maxSum = std::max(maxSum, events[i][2]);

      // 4. 使用二分查找找到第一個與當前活動不重疊的活動
      //    l 和 r 用於二分查找的左右邊界
      int l = i + 1, r = n - 1, bestIndex = n; // 初始化 bestIndex 為 n
      while (l <= r) {
        int mid = l + (r - l) / 2; // 計算中間索引
        if (events[mid][0] > events[i][1]) { // 如果 mid 的開始時間大於當前活動的結束時間
          bestIndex = mid; // 更新最佳不重疊活動索引
          r = mid - 1; // 繼續在左半部分查找
        } else {
          l = mid + 1; // 否則繼續在右半部分查找
        }
      }

      // 5. 如果找到不重疊的活動，計算選擇當前活動和該活動的價值和
      if (bestIndex < n)
        maxSum = std::max(maxSum, events[i][2] + suffMax[bestIndex]);
    }

    // 6. 返回最大的價值和
    return maxSum;
  }
};
