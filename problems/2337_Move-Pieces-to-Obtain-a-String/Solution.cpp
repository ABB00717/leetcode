#include <string>
using namespace std;

class Solution {
public:
  bool canChange(string start, string target) {
    int startIndex = 0, targetIndex = 0;
    int n = start.size();

    while (startIndex < n || targetIndex < n) {
      // 跳過 '_' 字元
      while (startIndex < n && start[startIndex] == '_')
        startIndex++;
      while (targetIndex < n && target[targetIndex] == '_')
        targetIndex++;

      // 如果一個到結尾，另一個沒到，無法匹配
      if (startIndex == n || targetIndex == n)
        return startIndex == targetIndex;

      // 字元不同則無法匹配
      if (start[startIndex] != target[targetIndex])
        return false;

      // 驗證移動規則
      if (start[startIndex] == 'L' && startIndex < targetIndex)
        return false;
      if (start[startIndex] == 'R' && startIndex > targetIndex)
        return false;

      // 移動指針
      startIndex++;
      targetIndex++;
    }

    return true;
  }
};
