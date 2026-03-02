#include <vector>
class Solution {
public:
  int xorAllNums(std::vector<int> &nums1, std::vector<int> &nums2) {
    int nums1Size = nums1.size(), nums2Size = nums2.size();
    int xorNums1 = 0, xorNums2 = 0;

    // 計算 nums1 和 nums2 的整體 XOR
    for (int num : nums1) {
      xorNums1 ^= num;
    }
    for (int num : nums2) {
      xorNums2 ^= num;
    }

    // 判斷 XOR 結果根據奇偶性
    int result = 0;
    if (nums2Size % 2 == 1) {
      result ^= xorNums1;
    }
    if (nums1Size % 2 == 1) {
      result ^= xorNums2;
    }

    return result;
  }
};
