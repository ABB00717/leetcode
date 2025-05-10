#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int l = 0, r = nums.size();

    while (l < r) {
      if (nums[l] == val) {
        nums[l] = nums[--r];
      } else {
        ++l;
      }
    }

    return l;
  }
};
