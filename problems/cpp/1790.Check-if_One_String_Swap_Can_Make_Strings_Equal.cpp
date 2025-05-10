#include <string>
#include <utility>
class Solution {
public:
  bool areAlmostEqual(std::string s1, std::string s2) {
    if (s1.size() != s2.size()) return false;
    int n = s1.size();

    int forSwap = -1, backSwap = -1;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i]) continue;
      
      if (forSwap == -1) {
        forSwap = i;
      } else if (forSwap != -1 && backSwap == -1) {
        backSwap = i;
      } else {
        return false;
      }
    }

    if (forSwap == -1 && backSwap == -1) return true;
    if (forSwap == -1 || backSwap == -1) return false;

    std::swap(s1[forSwap], s1[backSwap]);
    return s1 == s2;
  }
};