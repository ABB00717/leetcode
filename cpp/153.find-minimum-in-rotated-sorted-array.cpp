/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] < nums[right]) 
                return nums[left];
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
// @lc code=end