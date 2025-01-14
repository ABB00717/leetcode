#include <set>
#include <vector>
class Solution {
public:
  std::vector<int> findThePrefixCommonArray(std::vector<int> &A,
                                            std::vector<int> &B) {
    int n = A.size();

    int count = 0;
    std::vector<int> result(n, 0);
    std::vector<int> freq(n+1, 0);
    for (int i = 0; i < n; i++) {
      freq[A[i]]++;
      if (freq[A[i]] == 2)
        count++;

      freq[B[i]]++;
      if (freq[B[i]] == 2)
        count++;

      result[i] = count;
    }

    return result;
  }
};
