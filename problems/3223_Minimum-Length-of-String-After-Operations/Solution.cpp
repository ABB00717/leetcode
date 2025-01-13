#include <deque>
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
  int minimumLength(std::string s) {
    // 5 -> 3
    // 6 -> 2 3

    std::vector<int> charFreq(26, 0);
    for (const char& c : s) 
      charFreq[c - 'a']++;

    int result = 0;
    for (int& freq : charFreq) {
      if (freq == 0)
        continue;

      if (freq % 2 == 1)
        result += 1;
      else
        result += 2;
    }

    return result;
  }
};
