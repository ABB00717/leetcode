#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::string kthDistinct(std::vector<std::string> &arr, int k) {
    std::unordered_map<std::string, int> count;

    for (auto& s : arr) {
      count[s]++;
    }

    for (auto& s: arr) {
      if (count[s] == 1) {
        k--;
      }
      if (k == 0) {
        return s;
      }
    }

    return "";
  }
};

int main() {
  Solution solution;
  std::vector<std::string> arr = {"d","b","c","b","c","a"};
  int k = 2;
  std::string output = solution.kthDistinct(arr, k);
  return 0;
}