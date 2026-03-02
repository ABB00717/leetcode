#include <queue>

#include "leetcode.h"

class Solution {
   public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long> power_damage;
        for (const int& p : power) {
            power_damage[p] += p;
        }

        vector<pair<int, long>> damages;
        for (const auto& [p, d] : power_damage) {
            damages.push_back({p, d});
        }
        
        int n = damages.size();
        if (n == 0)
            return 0;

        vector<long> dp(n, 0);
        for (int i = 0; i < n; i++) {
            long no_cast = i == 0 ? 0 : dp[i-1];

            long cast = damages[i].second;
            int j = i-1;
            while (j >= 0 && damages[j].first + 2 >= damages[i].first)
                j--;
            if (j >= 0)
                cast += dp[j];

            dp[i] = max(no_cast, cast);
        }

        return dp.back();
    }
};
