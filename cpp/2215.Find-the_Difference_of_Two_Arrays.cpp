#include <unordered_set>
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> findDifference(std::vector<int> &nums1,
                                               std::vector<int> &nums2) {
    std::unordered_set<int> s1(nums1.begin(), nums1.end()),
        s2(nums2.begin(), nums2.end());

    std::vector<int> diff1, diff2;
    diff1.reserve(s1.size());
    diff2.reserve(s2.size());

    for (int num : s1) {
      if (!s2.count(num)) {
        diff1.push_back(num);
      }
    }

    for (int num : s2) {
      if (!s1.count(num)) {
        diff2.push_back(num);
      }
    }

    return {diff1, diff2};
  }
};