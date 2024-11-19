#include <string>
class Solution {
public:
  bool isCircularSentence(std::string sentence) {
    if (sentence[0] != sentence[sentence.size() - 1])
      return false;

    for (int i = 0; i < sentence.size(); i++) {
      if (sentence[i] == ' ' && sentence[i + 1] != sentence[i - 1])
        return false;
    }

    return true;
  }
};