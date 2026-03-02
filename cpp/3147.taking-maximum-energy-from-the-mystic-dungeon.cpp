#include "leetcode.h"

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int round = min(n, k);

        int result = INT_MIN;
        for (int i = 0; i < round; i++) {
            int sum = 0;
            
            int j;
            for (j = i; j < n; j += k) {
                sum += energy[j];
            }
            for (j = i; j < n; j += k) {
                result = max(result, sum);
                sum -= energy[j];
            }
        }

        return result;
    }
};
