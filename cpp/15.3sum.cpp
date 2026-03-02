class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = -nums[i];
            int left = i+1, right = nums.size()-1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < complement) {
                    left++;
                } else if (sum > complement) {
                    right--;
                } else {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    result.push_back(triplet);

                    while (left < right && nums[left] == triplet[1]) left++;
                    while (left < right && nums[right] == triplet[2]) right--;                   
                }
            }
            
        }

        return result;
    }
};