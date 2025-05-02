#include <climits>
#include <vector>
class Solution {
public:
  bool increasingTriplet(std::vector<int> &nums) {
    int low = INT_MAX, mid = INT_MAX;

    for (int num : nums) {
      if (low < mid && num > mid) {
        return true;
      } else if (num < mid && num > low) {
        mid = num;
      } else if (num < low) {
        low = num;
      }
    }

    return false;
  }
};