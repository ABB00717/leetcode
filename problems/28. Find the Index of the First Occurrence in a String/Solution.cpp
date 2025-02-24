#include <string>
#include <vector>

// LPS 但我其實搞不太懂耶
class Solution {
private:
  std::vector<int> computeLPS(std::string needle) {
    int n = needle.size(), len = 0;
    std::vector<int> lps(n, 0);

    for (int i = 1; i < n; ) {
      if (needle[i] == needle[len]) {
        lps[i++] = ++len;
      } else if (len) {
        len = lps[len - 1];
      } else {
        lps[i++] = 0;
      }
    }

    return lps;
  }
  
public:
  int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) return 0;
    std::vector<int> lps = computeLPS(needle);

    int i = 0, j = 0, m = haystack.size(), n = needle.size();
    while (i < m) {
      if (haystack[i] == needle[j]) {
        i++, j++;
        if (j == n) return i - n;
      } else if (j) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }

    return -1;
  }
};