/*
 * @lc app=leetcode id=2551 lang=c
 *
 * [2551] Put Marbles in Bags
 */
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

long long putMarbles(int* weights, int weightsSize, int k) {
    int* pairSums = malloc(sizeof(int) * weightsSize);
    for (int i = 0; i < weightsSize - 1; i++) {
        pairSums[i] = weights[i] + weights[i + 1];
    }

    qsort(pairSums, weightsSize - 1, sizeof(int), cmpfunc);

    long long max = 0, min = 0;
    for (int i = 0; i < k - 1; i++) {
        max += pairSums[i];
        min += pairSums[weightsSize - 2 - i];
    }

    return max - min;
}

// @lc code=start
// @lc code=end
