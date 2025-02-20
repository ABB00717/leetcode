#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
  std::string findDifferentBinaryString(std::vector<std::string> &nums) {
    int n = nums.size(), limit = std::pow(2, n);
    std::vector<int> decimals(n, 0);
    for (int i = 0; i < n; i++) {
      decimals[i] = std::stoi(nums[i], nullptr, 2); 
    }

    for (int decimal : decimals) {
      std::cout << decimal << std::endl;
    }
    
    int result = 0;
    for (int i = 0; i < limit; i++) {
      if (std::find(decimals.begin(), decimals.end(), i) == decimals.end()) {
        result = i;
        break;
      }
    }
    
    std::string binary;
    for (int i = 0; i < n; i++) {
      binary = std::to_string(result % 2) + binary;
      result /= 2;
    }

    return binary;
  }
};