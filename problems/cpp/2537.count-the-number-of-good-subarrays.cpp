#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countGood(std::vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();

        // 'pairs' stores the number of pairs (i, j) with i < j and nums[i] == nums[j] in the current window
        long long pairs = 0;
        int left = 0;
        std::unordered_map<int, int> counts; // counts[x] = number of times x appears in the current window
        for (int right = 0; right < n; right++) {
            int rightNum = nums[right];
            // Each occurrence of rightNum in the window forms a new pair with nums[right]
            pairs += counts[rightNum];
            // Add nums[right] to the window
            counts[rightNum]++;

            // Shrink the window from the left while the number of pairs is at least k
            while (pairs >= k) {
                // All subarrays starting at 'left' and ending at or after 'right' are good
                res += n - right;
                int leftNum = nums[left];
                // Remove nums[left] from the window and update pairs
                counts[leftNum]--;
                pairs -= counts[leftNum];
                left++;
            }
        }

        return res;
    }
};