#include "leetcode.h"

class Solution {
   public:
    int triangularSum(vector<int>& nums) {
        for (int n = nums.size(); n > 1; n--) {
            for (int i = 0; i < n - 1; i++) {
                nums[i] += nums[i + 1];
                nums[i] %= 10;
            }
        }

        return nums[0];
    }
};
