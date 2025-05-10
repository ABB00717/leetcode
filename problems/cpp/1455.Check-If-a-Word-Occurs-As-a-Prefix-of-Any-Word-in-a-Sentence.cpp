#include <cstring>
#include <sstream>
#include <string>

class Solution {
public:
  int isPrefixOfWord(std::string sentence, std::string searchWord) {
    std::istringstream iss(sentence);
    std::string word;
    int index = 1;

    while (iss >> word) {
      if (word.compare(0, searchWord.size(), searchWord) == 0) {
        return index;
      }
      index++;
    }

    return -1;
  }
};