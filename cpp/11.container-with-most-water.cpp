#include "leetcode.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int water = 0;
        while (l < r) {
            int waterlevel = min(height[l], height[r]);

            water = max(water, (r-l)*(waterlevel));

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return water;
    }
};
