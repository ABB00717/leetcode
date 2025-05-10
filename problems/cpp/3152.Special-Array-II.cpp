#include <vector>

class Solution {
private:
  // 尋找是否有值介於 lBound 和 rBound 之間
  bool binarySearch(const std::vector<int> &nonSpecialIndex, int lBound,
                    int rBound) {
    int l = 0, r = nonSpecialIndex.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nonSpecialIndex[mid] >= lBound && nonSpecialIndex[mid] <= rBound) return true;

      if (nonSpecialIndex[mid] < lBound) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return false;
  }

public:
  std::vector<bool> isArraySpecial(std::vector<int> &nums,
                                   std::vector<std::vector<int>> &queries) {
    std::vector<bool> result(queries.size(), true);
    std::vector<int> nonSpecialIndex; // 儲存不是 special 的 adjacent elements，紀錄左邊的 index
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] % 2 == nums[i + 1] % 2)
        nonSpecialIndex.push_back(i);
    }

    for (int i = 0; i < queries.size(); i++) {
      auto pair = queries[i];
      if (pair[0] == pair[1])
        continue;

      // 若 subarray 之中有不是 special 的 adjacent elements，則把 result 修改為 false
      if (binarySearch(nonSpecialIndex, pair[0], pair[1] - 1))
        result[i] = false;
    }

    return result;
  }
};
