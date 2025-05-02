#include <vector>
class Solution {
public:
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    int n = gas.size();
    int surplus = 0;
    int start = 0;
    int total = 0;
    
    for (int i = 0; i < n; i++) {
      int diff = gas[i] - cost[i];
      total += diff;
      surplus += diff;

      if (surplus < 0) {
        start = i + 1;
        surplus = 0;
      }
    }

    return total < 0 ? -1 : start;
  }
};