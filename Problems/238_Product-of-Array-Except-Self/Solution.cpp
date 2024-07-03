class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numSize = nums.size();

        vector<int> result(numSize, 1);
        vector<int> prefix(numSize+2, 1);
        vector<int> postfix(numSize+2, 1);

        for (int i = 1; i <= numSize; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for (int i = numSize; i >= 1; i--) {
            postfix[i] = postfix[i+1] * nums[i-1];
        }

        for (int i = 0; i < numSize; i++) {
            result[i] = prefix[i] * postfix[i+2];
        }

        return result;
    }
};