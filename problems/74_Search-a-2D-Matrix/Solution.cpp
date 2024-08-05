#include <algorithm>
#include <vector>
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    bool result = false;
    int matrixColSize = matrix[0].size(), matrixRowSize = matrix.size();

    int row = 0;

    int l = 0, r = matrixRowSize - 1;
    int mid = (l + r) / 2;
    while (matrix[std::max(0, mid - 1)][matrixColSize - 1] > target ||
           matrix[std::min(matrixRowSize - 1, mid)][matrixColSize - 1] <
               target) {
    }

    for (row = 0;
         row < matrixRowSize - 1 && matrix[row][matrixColSize - 1] < target;
         row++) {
    }

    l = 0, r = matrixColSize - 1;
    mid = (l + r) / 2;
    while (matrix[row][mid] != target) {
      if (matrix[row][l] > target || matrix[row][r] < target) {
        return false;
      } else if (matrix[row][mid] < target) {
        l = mid + 1;
      } else if (matrix[row][mid] > target) {
        r = mid - 1;
      }

      mid = (l + r) / 2;
    }

    return true;
  }
};
