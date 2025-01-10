#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<std::string> wordSubsets(std::vector<std::string> &words1,
                                       std::vector<std::string> &words2) {
    int a = 10;
    std::vector<int> maxFreq(26, 0);

    for (std::string word : words2) {
      std::vector<int> curFreq(26, 0);
      for (char ch : word) {
        curFreq[ch - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        if (curFreq[i] > maxFreq[i]) maxFreq[i] = curFreq[i];
      }
    }

    std::vector<std::string> result;
    for (std::string word : words1) {
      std::vector<int> curFreq(26, 0);
      for (char ch : word) {
        curFreq[ch - 'a']++;
      }

      bool universal = true;
      for (int i = 0; i < 26; i++) {
        if (curFreq[i] < maxFreq[i]) universal = false;
      }
      if (universal) result.push_back(word);
    }

    return result;
  }
};
