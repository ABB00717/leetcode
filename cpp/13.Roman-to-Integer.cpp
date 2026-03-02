#include <string>
class Solution {
public:
  int romanToInt(std::string s) {
    char previousSymbol;
    int result = 0;
    for (auto symbol : s) {
      switch (symbol) {
        case 'I':
          result += 1;
          break;
        case 'V':
          result += 5;
          if (previousSymbol == 'I') result -= 2;
          break;
        case 'X':
          result += 10;
          if (previousSymbol == 'I') result -= 2;
          break;
        case 'L':
          result += 50;
          if (previousSymbol == 'X') result -= 20;
          break;
        case 'C':
          result += 100;
          if (previousSymbol == 'X') result -= 20;
          break;
        case 'D':
          result += 500;
          if (previousSymbol == 'C') result -= 200;
          break;
        case 'M':
          result += 1000;
          if (previousSymbol == 'C') result -= 200;
          break;
      }

      previousSymbol = symbol;
    }

    return result;
  }
};
