class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> count;

        for (auto num : nums) {
            if (count[num])
                return true;
            
            count[num] = true;
        }

        return false;
    }
};