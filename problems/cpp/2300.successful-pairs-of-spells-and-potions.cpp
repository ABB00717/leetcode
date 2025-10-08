#include <algorithm>
#include <functional>

#include "leetcode.h"

class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> result(n, 0);
        // large -> small
        sort(potions.begin(), potions.end(), greater<int>());

        for (int i = 0; i < n; i++) {
            // ceiling division
            long long target = (success + spells[i] - 1) / spells[i];

            int least_index = binary_search(target, potions);

            if (least_index == -1)
                result[i] = m;
            else
                result[i] = least_index;
        }

        return result;
    }

   private:
    int binary_search(long long target, vector<int>& arr) {
        int result = -1;
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (arr[m] >= target) {
                l = m + 1;
            } else {
                result = m;
                r = m - 1;
            }
        }

        return result;
    }
};

int main() {
    vector<int> spells = {3, 1, 2}, potions = {8, 5, 8};
    int success = 16;
    Solution sol;
    sol.successfulPairs(spells, potions, success);
}
