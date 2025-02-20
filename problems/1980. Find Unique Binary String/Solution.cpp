#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
  std::string findDifferentBinaryString(std::vector<std::string> &nums) {
    int n = nums.size();

    std::string result;
    for (int i = 0; i < n; i++) {
      result += nums[i][i] == '0' ? '1' : '0';
    }

    return result;
  }
};