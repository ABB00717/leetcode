#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  int firstCompleteIndex(std::vector<int> &arr, std::vector<std::vector<int>> &mat) {
    int rowSize = mat.size(), colSize = mat[0].size();
    std::vector<int> row(rowSize, 0), col(colSize, 0);
    std::pmr::unordered_map<int, std::pair<int, int>> numToPos;

    for (int i = 0; i < rowSize; i++) {
      for (int j = 0; j < colSize; j++) {
        numToPos[mat[i][j]] = {i, j};
      }
    }

    for (int i = 0; i < arr.size(); i++) {
      auto [rowPos, colPos] = numToPos[arr[i]];
      row[rowPos]++;
      col[colPos]++;

      if (row[rowPos] == colSize || col[colPos] == rowSize)
        return i;
    }

    return -1;
  }
};