#include <algorithm>
#include <vector>
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    bool result = false;
    int matrixColSize = matrix[0].size(), matrixRowSize = matrix.size();

    int row = 0;
    for (row = 0;
         row < matrixRowSize && matrix[row][matrixColSize - 1] < target;
         row++) {
    }
  }
};
