/*
 * @lc app=leetcode id=1534 lang=cpp
 *
 * [1534] Count Good Triplets
 */

// @lc code=start
#include <cstdlib>
#include <vector>
class Solution {
   public:
    int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (std::abs(arr[i] - arr[j]) <= a &&
                        std::abs(arr[j] - arr[k]) <= b &&
                        std::abs(arr[i] - arr[k]) <= c) {
                            res++;
                    }
                }
            }
        }

        return res;
    }
};

// @lc code=end
