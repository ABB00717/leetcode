#include <vector>

class Solution {
public:
  std::vector<int> xorQueries(std::vector<int> &arr, std::vector<std::vector<int>> &queries) {
    std::vector<int> result(queries.size(), 0);

    for (int i = 0; i < queries.size(); i++) {
      for (int j = queries[i][0]; j <= queries[i][1]; j++) {
        result[i] ^= arr[j];
      }
    }

    return result;
  }
};