/*
 * @lc app=leetcode id=2200 lang=c
 *
 * [2200] Find All K-Distant Indices in an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    int right = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key) {
            int left = fmax(right, i - k);
            right = fmin(numsSize - 1, i + k) + 1;

            for (int j = left; j < right; j++) {
                result[count++] = j;
            }
        }
    }

    *returnSize = count;
    return result;
}
// @lc code=end

