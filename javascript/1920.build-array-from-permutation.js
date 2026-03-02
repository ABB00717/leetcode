/*
 * @lc app=leetcode id=1920 lang=javascript
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function (nums) {
    const result = new Array(nums.length);

    for (let i = 0; i < nums.length; i++) {
        result[i] = nums[nums[i]];
    }

    return result;
};
// @lc code=end

