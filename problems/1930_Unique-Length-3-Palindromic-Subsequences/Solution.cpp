#include <algorithm> // for lower_bound
#include <string>
#include <vector>

class Solution {
public:
  /*因為只要求三個字元的 Palindrom，所以只要檢測 prefix == suffix 以及中間某個字元有沒有出現即可*/
  int countPalindromicSubsequence(const std::string &s) {
    std::vector<std::vector<int>> positions(26);
    for (int i = 0; i < (int)s.size(); i++) {
      positions[s[i] - 'a'].push_back(i);
    }

    int result = 0;
    for (int c = 0; c < 26; c++) {
      if (positions[c].size() < 2)
        continue;

      int l = positions[c].front();
      int r = positions[c].back();
      if (r - l < 2) {
        continue;
      }

      for (int mid = 0; mid < 26; mid++) {
        // binary search：找 positions[mid] 中「第一個 >= (l+1)」的迭代器 it
        auto it = std::lower_bound(positions[mid].begin(), positions[mid].end(),
                                   l + 1);
        // 如果 it 還在範圍內，且 *it < r，代表區間 (l, r) 有字元 mid
        if (it != positions[mid].end() && *it < r) {
          result++;
        }
      }
    }
    return result;
  }
};