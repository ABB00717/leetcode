/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> partitionLabels(std::string s) {
        int n = s.size();
        std::vector<int> result;

        std::vector<int> prefixSum(
            n,
            0);  // Used to track the balance between character starts and ends
        std::unordered_map<char, int> meet; // Keeps track of the last seen index of each character
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (!meet.count(ch)) {
                // First time seeing this character, store its index
                meet[ch] = i; 
            } else {
                // Seen the character before
                // +1 at the first index where it appeared
                // -1 at the current index to close the region
                prefixSum[meet[ch]]++;
                prefixSum[i]--;

                // Update the last seen index to current one
                meet[ch] = i;
            }
        }

        // Scan through prefixSum and count partitions
        int imbalance = 0, partition = 0;
        for (int i = 0; i < n; i++) {
            partition++; // Increment partition size
            imbalance += prefixSum[i]; // Accumulate imbalance count

            // If imbalance is 0, this means all open intervals are closed
            if (imbalance == 0) { 
                result.push_back(partition); // Store the size of the current partition
                partition = 0; // Reset for the next partition
            }
        }

        return result;
    }
};

// @lc code=end
