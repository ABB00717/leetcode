#include <algorithm>
#include <cmath>
#include <vector>
class Solution {
public:
  int minEatingSpeed(std::vector<int> &piles, int h) {
    int left = 1;
    int right = *std::max_element(piles.begin(), piles.end());

    while (left < right) {
      int mid = left + (right - left) / 2;
      int hours = 0;

      for (int pile : piles) {
        hours += ceil(double(pile) / mid);
      }

      if (hours <= h) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};

int main(int argc, char *argv[]) {
  Solution solution;

  std::vector<int> piles = {3, 6, 7, 11};
  int h = 8;
  int result = solution.minEatingSpeed(piles, h);

  return 0;
}
