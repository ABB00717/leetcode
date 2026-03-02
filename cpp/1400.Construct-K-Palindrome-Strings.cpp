#include <string>
#include <vector>
class Solution {
public:
  bool canConstruct(std::string s, int k) {
    if (s.size() < k)
      return false;

    std::vector<int> count(26, 0);
    for (char c : s)
      count[c - 'a']++;

    int odd = 0;
    for (int i = 0; i < 26; i++)
      if (count[i] % 2)
        odd++;
    
    return odd <= k;
  }
};
