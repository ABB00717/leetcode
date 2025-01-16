#include <bitset>
#include <cmath>
#include <string>
#include <vector>
class Solution {
public:
  int xorAllNums(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<long long int> bitCount(32, 0);

    int nums1Size = nums1.size(), nums2Size = nums2.size();
    for (int num : nums1) {
      std::string numBinary = std::bitset<32>(num).to_string();
      for (int i = 0; i < 32; i++) {
        if (numBinary[i] == '1')
          bitCount[i] += 1 * nums2Size;
      }
    }

    for (int num : nums2) {
      std::string numBinary = std::bitset<32>(num).to_string();
      for (int i = 0; i < 32; i++) {
        if (numBinary[i] == '1')
          bitCount[i] += 1 * nums1Size;
      }
    }

    int result = 0;
    for (int i = 0; i < 32; i++) {
      if (bitCount[i] % 2 == 1)
        result += std::pow(2, 31 - i);
    }

    return result;
  }
};