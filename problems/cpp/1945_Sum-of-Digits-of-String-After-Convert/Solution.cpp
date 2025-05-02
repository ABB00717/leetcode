#include <string>

class Solution {
public:
  int getLucky(std::string s, int k) {
    int sum = 0;

    for (char c : s) {
      int digit = c - 'a' + 1;
      sum += digit / 10 + digit % 10;
    }
    k--;

    while (k-- > 0) {
      int newSum = 0;
      
      while (sum > 0) {
        newSum += sum % 10;
        sum /= 10;
      }

      sum = newSum;
    }

    return sum;
  }
};