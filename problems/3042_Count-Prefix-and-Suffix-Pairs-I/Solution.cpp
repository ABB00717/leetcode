#include <string>
#include <vector>
class Solution {
private:
  bool isPrefixAndSuffix(std::string str1, std::string str2) {
    int str1Size = str1.size(), str2Size = str2.size();
    if (str1Size > str2Size) return false;
    
    for (int i = 0; i < str1Size; i++) {
      if (str1[i] != str2[i]) return false;
      if (str1[str1Size-1-i] != str2[str2Size-1-i]) return false;
    }
    
    return true;
  }
public:
  int countPrefixSuffixPairs(std::vector<std::string> &words) {
    int result = 0, n = words.size();
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (isPrefixAndSuffix(words[i], words[j])) result++;
      }
    }

    return result;
  }
};
