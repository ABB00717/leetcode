#include <set>
#include <string>
#include <vector>
class Solution {
private:
public:
  std::vector<std::string> stringMatching(std::vector<std::string> &words) {
    std::set<std::string> result;
    int n = words.size();
    
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (words[i].find(words[j]) != std::string::npos) result.insert(words[j]);
        if (words[j].find(words[i]) != std::string::npos) result.insert(words[i]);
      }
    }

    std::vector<std::string> resultVector(result.begin(), result.end());
    return resultVector;
  }
};
