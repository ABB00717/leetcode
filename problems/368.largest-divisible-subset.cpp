/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Sort the input array in ascending order. This helps in checking divisibility.
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // dp map to store the length of the largest divisible subset ending with a number
        // and the previous number in that subset. {number: {length, previous_number}}
        unordered_map<int, pair<int, int>> dp;
        // maxLength to keep track of the maximum length found so far.
        int maxLength = 0;
        // maxNum to keep track of the number that ends the longest divisible subset.
        int maxNum = -1;

        // Iterate through each number in the sorted array.
        for (int i = 0; i < n; i++) {
            // Initialize the dp entry for the current number.
            // The length is 1 (the number itself forms a subset), and the previous is -1 (no preceding element yet).
            dp[nums[i]] = {1, -1};

            // Iterate through all the numbers before the current number.
            for (int j = 0; j < i; j++) {
                // Check if the current number is divisible by the previous number.
                if (nums[i] % nums[j] == 0) {
                    // If it is divisible, check if including the current number extends the largest divisible subset ending at the previous number.
                    if (dp[nums[i]].first < dp[nums[j]].first + 1) {
                        // Update the length of the largest divisible subset ending at the current number.
                        dp[nums[i]].first = dp[nums[j]].first + 1;
                        // Update the previous number in the largest divisible subset ending at the current number.
                        dp[nums[i]].second = nums[j];
                    }
                }
            }

            // Update the overall maximum length and the number that ends this longest subset.
            if (dp[nums[i]].first > maxLength) {
                maxLength = dp[nums[i]].first;
                maxNum = nums[i];
            }
        }

        // Vector to store the result (the largest divisible subset).
        vector<int> ans;
        // Start backtracking from the number that ends the longest subset.
        int parentNum = maxNum;
        // Backtrack through the 'previous' pointers in the dp map to reconstruct the subset.
        while (parentNum != -1) {
            ans.push_back(parentNum);
            parentNum = dp[parentNum].second;
        }
        // The subset is built in reverse order, so reverse it to get the correct order.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// @lc code=end