#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxCount(std::vector<int> &banned, int n, int maxSum) {
    int result = 0, sum = 0;
    std::unordered_map<int, bool> bannedMap;

    for (auto bannedNum : banned)
      bannedMap[bannedNum] = true;

    for (int i = 1; i <= n; i++) {
      if (bannedMap[i])
        continue;

      sum += i;
      if (sum > maxSum)
        break;
      result++;
    }

    return result;
  }
};
