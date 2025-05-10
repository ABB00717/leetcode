#include <string>
#include <vector>

/*
這裡只需要用 result++ 而不用 C 去計算組合數量。是因為我們的dfs其實就已經算是在幫第n個字母找所有可能的組合了。
*/
class Solution {
private:
  int result = 0;

  void dfs(std::vector<int>& count) {
    for (int i = 0; i < 26; i++) {
      if (count[i] == 0) continue;
      result++;
      count[i]--;
      dfs(count);
      count[i]++;
    }
  }

public:
  int numTilePossibilities(std::string tiles) {
    std::vector<int> count(26, 0);
    for (char c : tiles) 
      count[c - 'A']++;

    dfs(count);
    return result;
  }
};
