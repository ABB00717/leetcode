#include <cstring>
#include <string>
#include <vector>

class Solution {
private:
  std::vector<std::string> split(std::string str, char delim) {
    std::vector<std::string> words;
    std::string word = "";
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == delim) {
        words.push_back(word);
        word = "";
      } else {
        word += str[i];
      }
    }
    words.push_back(word);
    return words;
  }
  
public:
  int isPrefixOfWord(std::string sentence, std::string searchWord) {
    int result = -1;    
    std::vector<std::string> words = split(sentence, ' ');

    for (int i = 0; i < words.size(); i++) {
      if (words[i].find(searchWord) == 0) {
        result = i + 1;
        break;
      }
    }

    return result;
  }
};