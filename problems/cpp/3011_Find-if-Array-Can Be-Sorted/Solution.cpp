#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
class Solution {
private:
  typedef struct {
    int val;
    int bitCount;
  } Bit;

public:
  bool canSortArray(std::vector<int> &nums) {
    std::vector<Bit> numBits;

    for (int num : nums) {
      int bitCount = 0, originalNum = num;
      while (num) {
        bitCount += num & 1;
        num >>= 1;
      }
      numBits.push_back({originalNum, bitCount});
    }

    for (int i = 0; i < nums.size()-1; i++) {
      for (int j = 0; j < nums.size()-1; j++) {
        if (numBits[j].bitCount == numBits[j+1].bitCount && numBits[j].val > numBits[j+1].val) {
          std::swap(numBits[j], numBits[j+1]);
        }
      }
    }

    for (int i = 0; i < numBits.size()-1; i++) {
      if (numBits[i].val > numBits[i+1].val) {
        return false;
      }
    }

    return true;
  }
};