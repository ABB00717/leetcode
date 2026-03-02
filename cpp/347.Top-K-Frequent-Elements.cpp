class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (auto num : nums)
            freq[num]++;
        
        vector<vector<int>> bucket(nums.size()+1);
        for (const auto& [number, time] : freq)
            bucket[time].push_back(number);

        vector<int> result;
        for (int time = nums.size(); time >= 0; time--) {
            for (auto num : bucket[time])
                result.push_back(num);

            if (result.size() == k)
                return result;
        }

        return result;
    }
};