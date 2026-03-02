#include <sstream>
#include <string>
class Solution {
public:
  std::string reverseWords(std::string s) {
    std::stringstream ss(s);
    
    std::string word, reversedWords;

    while (ss >> word) {
      reversedWords.insert(0, " " + word);
    }

    if (reversedWords.empty()) return "";
      reversedWords.erase(0, 1);

    return reversedWords;
  }
};