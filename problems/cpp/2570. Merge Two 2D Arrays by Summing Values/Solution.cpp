#include <vector>
using namespace std;

class Solution {
private:
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    vector<vector<int>> result;
    int n1 = nums1.size(), n2 = nums2.size();

    int i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2) {
      if (nums1[i1][0] == nums2[i2][0]) {
        result.push_back({nums1[i1][0], nums1[i1++][1] + nums2[i2++][1]});
      } else if (nums1[i1][0] > nums2[i2][0]) {
        result.push_back(nums2[i2++]);
      } else {
        result.push_back(nums1[i1++]);
      }
    }

    while (i2 < n2) {
      result.push_back(nums2[i2++]);
    }
    while (i1 < n1) {
      result.push_back(nums1[i1++]);
    }

    return result;
  }
};