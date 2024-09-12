#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int countConsistentStrings(std::string allowed, std::vector<std::string> &words) {
    std::unordered_map<char, bool> characters;

    for (char c : allowed) {
      characters[c] = true;
    }

    int count = 0;
    for (auto &word : words) {
      for (char c : word) {
        if (characters.find(c) == characters.end()) {
          count++;
          break;
        }
      }
    }

    return words.size() - count;
  }
};