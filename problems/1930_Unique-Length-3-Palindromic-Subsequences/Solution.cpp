#include <cstdlib>
#include <string>
#include <vector>
class Solution {
public:
  /*因為只要求三個字元的 Palindrom，所以只要檢測 prefix == suffix 以及中間某個字元有沒有出現即可*/
  int countPalindromicSubsequence(std::string s) {
    if (s.size() < 3)
      return 0;

    std::vector<std::vector<int>> prefixCount(
        26, std::vector<int>(s.size() + 1, 0));
    prefixCount[s[0] - 'a'][0] = 1;
    for (int i = 1; i < s.size(); i++) {
      for (char target = 'a'; target <= 'z'; target++) {
        prefixCount[target - 'a'][i] = prefixCount[target - 'a'][i - 1];
        if (s[i] == target)
          prefixCount[target - 'a'][i]++;
      }
    }

    std::vector<std::vector<int>> positions(26);
    for (int i = 0; i < s.size(); i++) {
      positions[s[i]-'a'].push_back(i);
    }

    int result = 0;
    for (char prefix = 0; prefix < 26; prefix++) {
      if (positions[prefix].size() < 2) continue;
      int l = positions[prefix][0], r = positions[prefix][positions[prefix].size()-1];

      for (char mid = 0; mid < 26; mid++) {
        if (prefixCount[mid][r-1] - prefixCount[mid][l] != 0) result++;
      }
    }

    return result;
  }
};