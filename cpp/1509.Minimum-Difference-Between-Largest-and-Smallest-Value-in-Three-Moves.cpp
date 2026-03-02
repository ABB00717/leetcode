class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4)
            return 0;

        std::sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;

        for (int left = 0, right = nums.size() - 4; left < 4; left++, right++) {
            minDiff = std::min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};