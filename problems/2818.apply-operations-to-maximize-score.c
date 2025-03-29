/*
 * @lc app=leetcode id=2818 lang=c
 *
 * [2818] Apply Operations to Maximize Score
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
const int MOD = 1e9 + 7;

// Calculate the prime score of a number: the number of distinct prime factors.
// Note: 1 has no prime factors, so its prime score is defined as 0.
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

// Fast modular exponentiation: calculates (base^exp) mod mod.
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

typedef struct {
    int first;
    long long second;
} pair_t;

// Comparator for qsort: sort in descending order by first.
int cmp(const void* a, const void* b) {
    const pair_t* p1 = a;
    const pair_t* p2 = b;
    return p2->first - p1->first;
}

int maximumScore(int* nums, int n, int k) {
    // Calculate the prime score for each number.
    int* P = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        P[i] = calPrimeScore(nums[i]);
    }

    // Calculate the valid left range for each position using a monotonic stack.
    // left[i]: the number of positions to the left (including i) such that in the subarray,
    // all elements to the left of i have a prime score < P[i].
    int* left = calloc(n, sizeof(int));
    int* stack = malloc(n * sizeof(int));
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && P[stack[top]] < P[i])
            top--;
        left[i] = top < 0 ? i + 1 : i - stack[top];
        stack[++top] = i;
    }

    // Calculate the valid right range for each position using a monotonic stack.
    // right[i]: the number of positions to the right (including i) such that in the subarray,
    // all elements to the right of i have a prime score <= P[i].
    int* right = calloc(n, sizeof(int));
    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && P[stack[top]] <= P[i])
            top--;
        right[i] = top < 0 ? n - i : stack[top] - i;
        stack[++top] = i;
    }

    // Each index i is part of left[i] * right[i] valid subarrays.
    long long* count = calloc(n, sizeof(long long));
    for (int i = 0; i < n; i++) {
        count[i] = (long long) left[i] * right[i];
    }

    // Store each candidate (nums[i], count[i]) into an array and sort them in descending order by nums[i].
    pair_t* candidates = malloc(n * sizeof(pair_t));
    for (int i = 0; i < n; i++) {
        candidates[i] = (pair_t){nums[i], count[i]};
    }
    qsort(candidates, n, sizeof(pair_t), cmp);

    // Greedy: multiply by the larger numbers as many times as possible.
    long long result = 1;
    int remaining = k;
    for (int i = 0; i < n; i++) {
        if (remaining <= 0)
            break;
        int times = min((long long)remaining, candidates[i].second);
        result = (result * modexp(candidates[i].first, times, MOD)) % MOD;
        remaining -= times;
    }
    
    // Free allocated memory (if needed).
    free(P);
    free(left);
    free(right);
    free(stack);
    free(count);
    free(candidates);
    
    return (int)result;
}

// @lc code=end

// int main() {
//     // Example usage
//     int nums[] = {1,7,11,1,5};
//     int k = 14;
//     int n = sizeof(nums) / sizeof(nums[0]);
//     printf("%d\n", maximumScore(nums, n, k));
// }
