#include <numeric>
#include "leetcode.h"

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n_skill = skill.size();
        int n_mana = mana.size();

        // If there's only 1 wizard, simply calculate the result
        if (skill.size() == 1)
            return skill[0] * accumulate(mana.begin(), mana.end(), 0LL);

        // Init the result of the first potion
        vector<long long> result(n_skill+1, 0);
        for (int i = 0; i < n_skill; i++) {
            result[i+1] = result[i] + mana[0] * skill[i];
        }

        for (int i_mana = 1; i_mana < n_mana; i_mana++) {
            // Find the i_largest which represents the best minimum time
            int i_largest = 0;
            result[0] = result[1];
            for (int i = 0; i < n_skill; i++) {
                result[i+1] = result[i] + mana[i_mana] * skill[i];

                if (i < result.size()-2 && result[i+1] < result[i+2]) {
                    i_largest = i+1;
                    result[i+1] = result[i+2];
                }
            }

            // Iterate again to adjust result values
            long long accu = 0;
            long long standard = result[i_largest];
            for (int i = i_largest-1; i >= 0; i--) {
                accu += mana[i_mana] * skill[i];
                result[i] = standard - accu;
            }
        }

        return result.back();
    }
};

int main() {
    Solution s;
    vector<int> skill = {1,5,2,4}, mana = {5,1,4,2};
    s.minTime(skill, mana);
}
