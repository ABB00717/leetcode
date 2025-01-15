#include <bitset>
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int num1OneCount = __builtin_popcount(num1),
        num2OneCount = __builtin_popcount(num2);

    if (num1OneCount == num2OneCount)
      return num1;

    std::string num1Binary = std::bitset<32>(num1).to_string();
    num1Binary.erase(0, num1Binary.find_first_not_of('0'));

    if (num1OneCount > num2OneCount) {
      while (num1OneCount != num2OneCount) {
        size_t lastZero = num1Binary.find_last_of('1');
        if (lastZero == std::string::npos)
          break;
        num1Binary[lastZero] = '0';
        num1OneCount--;
      }
    } else if (num1OneCount < num2OneCount) {
      while (num1OneCount != num2OneCount) {
        size_t lastOne = num1Binary.find_last_of('0');
        if (lastOne == std::string::npos)
          num1Binary = "1" + num1Binary;
        else
          num1Binary[lastOne] = '1';
        num1OneCount++;
      }
    }

    if (num1Binary.empty())
      return 0;

    return std::stoi(num1Binary, nullptr, 2);
  }
};