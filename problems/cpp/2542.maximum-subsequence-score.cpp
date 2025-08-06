#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    /* 
     * @brief Calculates the maximum score from two arrays
     *
     * @details
     * The problem is to find a subsequence of `nums1` of size k that,
     * when its sum multiply the minimum of the corresponding `nums2` values, yields 
     * the maximum score.
     *
     * 1. The first k largest number of `nums2` are absolutely impossible to be a multiplier.
     * 2. We can add up the corresponding value in `nums1` first.
     * 3. The numbers in `nums2` index after k is guaranteed to be a multiplier. So if the size of
     * subsequence sum of `sum1` is greater than k, we need to kick out the smallest value in the sum of `nums1`.
     * 4. Keep going through the process, we could find the maximum score.
     * */
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> nums;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            nums.emplace_back(nums2[i], nums1[i]);
        }
        // Sort `nums2` in descending order
        sort(nums.rbegin(), nums.rend());

        long long result = 0;
        long long sum = 0;
        // By using priority queue, we can quickly remove the smallest value from the sum of `nums1` subsequence
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int i = 0; i < n; i++) {
            // Add the current `nums1` value to the sum and pq
            sum += nums[i].second;
            pq.push(nums[i].second);

            // If the size of the sum of subsequence `nums1` is greater than k, 
            // we need to remove the smallest value from it.
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            // We have the valid subsequence if the size is k
            if (pq.size() == k) {
                // Calculate the score and compare it with the current maximum
                result = max(result, (long long)sum * nums[i].first);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {
        1, 3, 3, 2
    };
    vector<int> nums2 = {
        2, 1, 3, 4
    };
    solution.maxScore(nums1, nums2, 3);
}
