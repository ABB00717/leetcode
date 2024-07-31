#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(n, n, "", result);
    return result;
  }

private:
  void generate(int l, int r, string cur, vector<string> &result) {
    if (l == 0 && r == 0) {
      result.push_back(cur);
      return;
    }

    if (l > 0) {
      generate(l - 1, r, cur + '(', result);
    }

    if (r > l) {
      generate(l, r - 1, cur + ')', result);
    }
  }
};
