#include <algorithm>
#include <queue>
#include <vector>
class Solution {
public:
  long long maxSum(std::vector<std::vector<int>> &grid, std::vector<int> &limits, int k) {
    std::priority_queue<int> pq;

    for (int i = 0; i < grid.size(); i++) {
      std::sort(grid[i].begin(), grid[i].end(), std::greater<int>());
      for (int j = 0; j < limits[i]; j++) {
        pq.push(grid[i][j]);
      }
    }

    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += pq.top();
      pq.pop();
    }

    return ans;
  }
};