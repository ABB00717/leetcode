#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> candidates;

        for (const int& num : nums) {
            if (candidates.size() == k) {
                candidates.push(num);
                candidates.pop();
                continue;
            }

            candidates.push(num);
        }

        return candidates.top();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,2,1,5,6,4};
    solution.findKthLargest(nums, 2);
}
