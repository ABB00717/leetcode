#include <string>
#include <vector>
class Solution {
private:
  const std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  bool isVowel(char ch) {
    for (auto vowel : vowels)
      if (ch == vowel)
        return true;

    return false;
  }

  bool checkBEVowel(std::string word) {
    return isVowel(word[0]) && isVowel(word[word.size() - 1]);
  }

public:
  /*PrefixSum 啊啊啊啊啊*/
  std::vector<int> vowelStrings(std::vector<std::string> &words,
                                std::vector<std::vector<int>> &queries) {
    std::vector<int> prefixSum(words.size(), 0);
    if (checkBEVowel(words[0]))
      prefixSum[0] = 1;

    for (int i = 1; i < words.size(); i++) {
      prefixSum[i] = prefixSum[i - 1];
      if (checkBEVowel(words[i]))
        prefixSum[i]++;
    }

    std::vector<int> result(queries.size());
    for (int i = 0; i < result.size(); i++) {
      if (queries[i][0] != 0)
        result[i] = prefixSum[queries[i][1]] - prefixSum[queries[i][0] - 1];
      else
        result[i] = prefixSum[queries[i][1]];
    }

    return result;
  }
};
