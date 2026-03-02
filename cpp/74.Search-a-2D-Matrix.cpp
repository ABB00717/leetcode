#include <algorithm>
#include <vector>
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    bool result = false;
    int matrixColSize = matrix[0].size(), matrixRowSize = matrix.size();

    int top = 0, bottom = matrixRowSize - 1;
    while (top <= bottom) {
      int mid = top + (bottom - top) / 2;
      if (matrix[mid][matrixColSize - 1] < target) {
        top = mid + 1;
      } else if (matrix[mid][matrixColSize - 1] > target) {
        bottom = mid - 1;
      } else {
        top = mid;
        break;
      }
    }

    if (top >= matrixRowSize || top < 0)
      return false;

    int row = top;
    int l = 0, r = matrixColSize - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (matrix[row][mid] < target) {
        l = mid + 1;
      } else if (matrix[row][mid] > target) {
        r = mid - 1;
      } else {
        return true;
      }
    }

    return false;
  }
};
