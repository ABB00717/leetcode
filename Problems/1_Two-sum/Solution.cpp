class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = target - num;
            
            if (num_to_index.find(complement) != num_to_index.end()) 
                return {num_to_index[complement][0], i};
            num_to_index[num] = i;
        }

        return {};
    }
};