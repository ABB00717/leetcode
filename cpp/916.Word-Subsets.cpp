#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<std::string> wordSubsets(std::vector<std::string> &words1,
                                       std::vector<std::string> &words2) {
    auto getFreq = [](const std::string &word) {
      std::vector<int> freq(26, 0);
      for (char ch : word)
        freq[ch - 'a']++;
      return freq;
    };

    std::vector<int> maxFreq(26, 0);
    for (const std::string &word : words2) {
      auto freq = getFreq(word);
      std::transform(maxFreq.begin(), maxFreq.end(), freq.begin(), maxFreq.begin(),
                     [](int lhs, int rhs) { return std::max(lhs, rhs); });
    }
    int totalMaxFreq = std::accumulate(maxFreq.begin(), maxFreq.end(), 0);

    std::vector<std::string> result;
    result.reserve(words1.size());
    for (std::string word : words1) {
      if (word.size() < totalMaxFreq)
        continue;

      auto freq = getFreq(word);

      if (std::equal(maxFreq.begin(), maxFreq.end(), freq.begin(), freq.end(),
                     [](int need, int have) {
                      return have >= need;
                     }))
        result.push_back(word);
    }

    return result;
  }
};
