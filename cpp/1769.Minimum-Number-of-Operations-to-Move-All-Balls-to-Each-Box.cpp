#include <cstdlib>
#include <string>
#include <vector>
class Solution {
public:
  std::vector<int> minOperations(std::string boxes) {
    int n = boxes.size();
    std::vector<int> indexPrefixSum(n + 1, 0), amountPrefixSum(n + 1, 0);

    for (int i = 0; i < n; i++) {
      indexPrefixSum[i + 1] = indexPrefixSum[i];
      amountPrefixSum[i + 1] = amountPrefixSum[i];

      if (boxes[i] == '1') {
        indexPrefixSum[i + 1] += i;
        amountPrefixSum[i + 1]++;
      }
    }

    std::vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
      int rAmount = amountPrefixSum.back() - amountPrefixSum[i],
          lAmount = amountPrefixSum[i];
      int rIndex = indexPrefixSum.back() - indexPrefixSum[i],
          lIndex = indexPrefixSum[i];

      result[i] = (i * lAmount - lIndex) + (rIndex - i * rAmount);
    }

    return result;
  }
};