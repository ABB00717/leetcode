/*
* Constrains:
*   pileSize <= h
*
* Goal: Eat all piles of banana without minimum effort
*
* Estimate the result from the highest value
*
*/

#include <math.h>
int minEatingSpeed(int *piles, int pilesSize, int h) {
    int l = 1;
    int r = 1;
    for (int i = 1; i < pilesSize; i++)
        r = piles[i] > r ? piles[i] : r;
    int result = r;

    while (l <= r) {
        int m = l + (r - l) / 2;
        long long hours = 0;

        for (int i = 0; i < pilesSize; i++) {
            hours += ceil((double)piles[i] / m);
        }

        if (hours > h) {
            l = m + 1;
        } else {
            result = m;
            r = m - 1;
        }
    }

    return result;
}
