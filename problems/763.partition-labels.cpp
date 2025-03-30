/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> lastIndex(26, 0);
        std::vector<int> result;
        int n = s.size();

        // No need to record firstIndex, since we can track partition during iteration
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        int end = 0, start = 0;
        for (int i = 0; i < n; i++) {
            // Extent the current partition to include the last occurence of the current cahracter
            end = std::max(end, lastIndex[s[i]-'a']);

            // where i reaches the end, all character in the current partition are fully include
            if (end == i) {
                // Store the size of the current partition
                result.push_back(end - start + 1);
                // Start a new partition
                start = i + 1;
            }
        }

        return result;
    }
};

// @lc code=end
