#include <vector>

class Solution {
public:
  std::vector<int> xorQueries(std::vector<int> &arr, std::vector<std::vector<int>> &queries) {
    std::vector<int> result(queries.size(), 0), prefixXor(arr.size() + 1, 0);
    for (int i = 1; i <= arr.size(); i++) {
      prefixXor[i] = prefixXor[i - 1] ^ arr[i - 1];
    }

    for (int i = 0; i < queries.size(); i++) {
      result[i] = prefixXor[queries[i][0]] ^ prefixXor[queries[i][1]];
    }

    return result;
  }
};