#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        for (int l = 0; l < n-k; l++) {
            // num, count
            map<int, int> count;
            int max = 0;
            for (int i = l; i < l+k; i++) {
                if (!count.count(nums[i]))
                    count[nums[i]] = 1;
                else
                    count[nums[i]]++;
                max = max > count[nums[i]] ? max : count[nums[i]];
            }

            int temp = 0;
            for (auto it : count) {
                if (it.second == max)
                    temp += it.second * it.first;
            }

            result.push_back(temp);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1,1,2,2,3,4,2,3};
    Solution s;
    s.findXSum(nums, 6, 2);
}
