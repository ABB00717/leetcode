#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
class Solution {
public:
  /*
  能先塞大的 char 就塞，如果到極限就換次大的。

  每次在塞之前都先 pop 掉，用完之後假如 freq > 0 那麼就放回去。
  */
  std::string repeatLimitedString(std::string s, int repeatLimit) {
    std::unordered_map<char, int> freqMap;
    for (char& ch : s) {
      freqMap[ch]++;
    }

    std::priority_queue<std::pair<char, int>> maxHeap;
    for (auto& entry : freqMap) {
      maxHeap.push({entry.first, entry.second});
    }

    std::string result;
    while (!maxHeap.empty()) {
      auto [char1, freq1] = maxHeap.top();
      maxHeap.pop();

      int insertCount = std::min(freq1, repeatLimit);
      freq1 -= insertCount;
      result.append(insertCount, char1);

      if (freq1 > 0) {
        if (!maxHeap.empty()) {
          auto [char2, freq2] = maxHeap.top();
          maxHeap.pop();

          freq2--;
          result.push_back(char2);
          
          if (freq2 > 0)
            maxHeap.push({char2, freq2});
          maxHeap.push({char1, freq1});
        } else {
          break;
        }
      }
    }

    return result;
  }
};