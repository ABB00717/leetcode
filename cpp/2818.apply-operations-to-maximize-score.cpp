/*
 * @lc app=leetcode id=2818 lang=cpp
 *
 * [2818] Apply Operations to Maximize Score
 */

// @lc code=start

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Calculate the prime score of a number: the number of distinct prime factor
// Warning: 1 has no prime factors, so its prime score is defined as 0
int calPrimeScore(int num) {
    int primeScore = 0;
    for (int p = 2; p * p <= num; p++) {
        if (num % p == 0) {
            primeScore++;
            while (num % p == 0)
                num /= p;
        }
    }
    if (num > 1)
        primeScore++;
    return primeScore;
}

// Fast modular exponentiation: calculates (base^exp) mod mod
long long modexp(long long base, int exp, int mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

class Solution {
   public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        // Calculate the prime score for each numbers
        vector<int> P(n);
        for (int i = 0; i < n; i++) {
            P[i] = calPrimeScore(nums[i]);
        }

        // calculate the valid left range for each position using a monotonic stack
        // left[i]: the number of positions to the left (including i) such that in the subarr.
        // all elements to the left of i have a prime score < P[i]
        vector<int> left(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && P[st.top()] < P[i])
                st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        // calculate the valid right range for each position using a monotonic stack
        // right[i]: the number of positions to the right (including i) such that in the subarr
        // all elements to the right of i have prime score <= P[i]
        vector<int> right(n, 0);
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && P[st.top()] <= P[i])
                st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // Each index i is part of left[i] * right[i] valid subarrays
        vector<long long> count(n, 0);
        for (int i = 0; i < n; i++) {
            count[i] = (long long)left[i] * right[i];
        }

        // Store each candidate (nums[i], count[i]) into a vector and sort them in descending order by nums[i]
        vector<pair<int, long long>> candidates;
        for (int i = 0; i < n; i++) {
            candidates.push_back({nums[i], count[i]});
        }
        sort(candidates.begin(), candidates.end(),
             [](const pair<int, long long>& a, const pair<int, long long>& b) {
                 return a.first > b.first;
             });

        // Greedy: multiply by the larger numbers as many times as possible.
        long long result = 1;
        int remaining = k;
        for (auto& cand : candidates) {
            if (remaining <= 0)
                break;
            // The number of times to use this candidate is the minimum of remaining and cand.second
            int times = min((long long)remaining, cand.second);
            // Multiply result by cand.first raised to the power of 'times (mod MOD).
            result = (result * modexp(cand.first, times, MOD)) % MOD;
            remaining -= times;
        }

        return (int)result;
    }
};

// @lc code=end

//  // Test main (uncomment if needed)
// #include <iostream>
// int main(){
//     Solution sol;
//     vector<int> nums1 = {8, 3, 9, 3, 8};
//     int k1 = 2;
//     // Expected output: 81
//     cout << sol.maximumScore(nums1, k1) << endl;

//     vector<int> nums2 = {19, 12, 14, 6, 10, 18};
//     int k2 = 3;
//     // Expected optput: 4788
//     cout << sol.maximumScore(nums2, k2) << endl;

//     return 0;
// }