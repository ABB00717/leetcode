#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        std::sort(nums.begin(), nums.end(), [&](const int& a, const int& b) {
            return freq[a] < freq[b] || freq[a] == freq[b] && a > b;
        });

        return nums;
    }
};
