#include <cmath>
#include <utility>
#include <vector>
class Solution {
private:
  double helper(double line, std::vector<std::vector<int>> &squares) {
    double aAbove = 0, aBelow = 0;
    int n = squares.size();
    for (int i = 0; i < n; i++) {
      int x = squares[i][0], y = squares[i][1];
      int l = squares[i][2];
      double total = std::pow(l, 2);

      if (line <= y) {
        aAbove += total;
      } else if (line >= y + l) {
        aBelow += total;
      } else {
        double aboveHeight = y + l - line;
        double belowHeight = line - y;
        aAbove += l * aboveHeight;
        aBelow += l * belowHeight;
      }
    }

    return aAbove - aBelow;
  }
  
public:
  double separateSquares(std::vector<std::vector<int>> &squares) {
    double high = 10e9, low = 0;

    while (high - low > 10e-6) {
      double mid = (low + high) / 2.0;
      double diff = helper(mid, squares);

      if (diff > 0) low = mid;
      else high = mid;
    }

    return high;
  }
};