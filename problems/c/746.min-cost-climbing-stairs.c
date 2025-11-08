#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void helper(int i, int *dp, const int *cost) {
    if (dp[i] != -1)
        return;
    if (dp[i-1] == -1)
        helper(i-1, dp, cost);
    if (dp[i-2] == -1)
        helper(i-2, dp, cost);

    int min_cost = min(dp[i-1]+cost[i], dp[i-2]+cost[i]);
    dp[i] = min_cost;
}

int minCostClimbingStairs(int* cost, int costSize) {
    int *dp = (int*)malloc(costSize * sizeof(int));
    for (int i = 0; i < costSize; i++)
        dp[i] = -1;
    dp[0] = cost[0];
    dp[1] = cost[1];

    helper(costSize-1, dp, cost);
    int result = min(dp[costSize-1], dp[costSize-2]);
    free(dp);
    return result;
}
