/*
 * @lc app=leetcode id=763 lang=c
 *
 * [763] Partition Labels
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int* partitionLabels(char* s, int* returnSize) {
    int* lastIndex = calloc(sizeof(int), 26);
    *returnSize = 0;
    int* result = NULL;
    int n = strlen(s);
    
    // No need to record firstIndex, since we can track partition during iteration
    for (int i = 0; i < n; i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    int end = 0, start = 0;
    for (int i = 0; i < n; i++) {
        // Extent the current partition to include the last occurence of the current cahracter
        end = MAX(end, lastIndex[s[i]-'a']);

        // where i reaches the end, all character in the current partition are fully include
        if (end == i) {
            // Store the size of the current partition
            result = realloc(result, sizeof(int) * (*returnSize + 1));
            result[(*returnSize)++] = (end - start + 1);
            // Start a new partition
            start = i + 1;
        }
    }

    return result;
}
// @lc code=end

