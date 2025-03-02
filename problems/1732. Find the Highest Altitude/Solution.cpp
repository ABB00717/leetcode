#include <algorithm>
#include <vector>
class Solution {
public:
  int largestAltitude(std::vector<int> &gain) {
    int curAlt = gain[0], maxAlt = gain[0];

    for (int i = 1; i < gain.size(); i++) {
      curAlt += gain[i];
      maxAlt = std::max(maxAlt, curAlt);
    }

    return std::max(0, maxAlt);
  }
};