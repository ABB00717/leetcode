#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int rob(int* nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    int *dp = (int*)malloc(numsSize * sizeof(int));
    int result = 0;
    dp[0] = nums[0];
    dp[1] = nums[1];

    for (int house = 2; house < numsSize; house++) {
        int max_stole = 0;
        for (int adj = house-2; adj >= 0; adj--) {
            max_stole = MAX(max_stole, dp[adj]);
        }
        dp[house] = max_stole + nums[house];
        printf("%d\n", dp[house]);
    }

    for (int i = 0; i < numsSize; i++) {
        result = MAX(result, nums[i]);
    }

    free(dp);
    return result;
}

int main() {
    int num[] = {2,7,9,3,1};
    int r = rob(num, 5);
}
