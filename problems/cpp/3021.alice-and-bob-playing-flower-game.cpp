#include "leetcode.h"

class Solution {
   public:
    long long flowerGame(int n, int m) {
        long long result = 0;
        int odd, even;

        // (odd, even)
        result += (long long)((n+1)/2) * (m/2);
        // (even, odd)
        result += (long long)(n/2) * ((m+1)/2);

        return result;
    }
};
