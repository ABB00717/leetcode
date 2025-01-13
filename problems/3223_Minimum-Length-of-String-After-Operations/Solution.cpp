#include <deque>
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
  int minimumLength(std::string s) {
    std::vector<char> resultString(s.size(), '-');

    std::vector<std::deque<int>> charCount(26, std::deque<int>());
    for (int i = 0; i < s.size(); i++)
      charCount[s[i] - 'a'].push_back(i);

    for (auto &charDeque : charCount) {
      while (charDeque.size() > 2) {
        charDeque.pop_front();
        charDeque.pop_back();
      }
    }

    for (int i = 0; i < 26; i++) {
      if (charCount[i].empty())
        continue;
      
      if (charCount[i].size() >= 1)
        resultString[charCount[i].front()] = i + 'a';
      if (charCount[i].size() > 1)
        resultString[charCount[i].back()] = i + 'a';
    }

    std::string result;
    for (auto &c : resultString) {
      if (c != '-')
        result += c;
    }

    return result.size();
  }
};
