#include <algorithm>
#include <cstdlib>
#include <functional>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<int> lexicographicallySmallestArray(std::vector<int> &nums, int limit) {
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end(), std::less<int>());

    int n = nums.size();
    std::vector<std::vector<int>> groups;
    std::pmr::unordered_map<int, int> numToGroupIndex;
    groups.push_back(std::vector<int>(1, sortedNums[0]));
    for (int i = 1; i < n; i++) {
      if (std::abs(sortedNums[i] - sortedNums[i-1]) <= limit) {
        groups.back().push_back(sortedNums[i]);
      } else {
        groups.push_back(std::vector<int>(1, sortedNums[i]));
      }
      
      numToGroupIndex[sortedNums[i]] = groups.size() - 1;
    }

    std::vector<int> result;
    for (int num : nums) {
      int index = numToGroupIndex[num];
      result.push_back(groups[index].front());
      groups[index].erase(groups[index].begin());
      }

    return result;
  }
};