#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
    std::unordered_map<std::string, bool> words;

    std::string word = "";
    for (auto &c : s1 + " " + s2 + " ") {
      if (c == ' ') {
        words[word] = words.find(word) == words.end() ? false : true;
        std::cout << word << std::endl;
        word = "";
      } else {
        word += c;
      }
    }

    std::vector<std::string> uncommon;
    for (auto &word : words) {
      if (!word.second) {
        uncommon.push_back(word.first);
      }
    }

    return uncommon;
  }
};