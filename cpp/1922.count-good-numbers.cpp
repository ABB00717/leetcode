class Solution {
    long long MOD = 1000000007;  // 定義模數

    // fast exponentiation function (calculates base^exp % MOD)
    long long power(long long base, long long exp) {
        // a^b = a^(b/2) * a^(b/2) if b is even
        // a^b = a * a^(b/2) * a^(b/2) if b is odd

        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

   public:
    int countGoodNumbers(long long n) {
        long long even_indices_count = (n + 1) / 2;
        long long odd_indices_count = n / 2;

        long long even_choices = power(5, even_indices_count);
        long long odd_choices = power(4, odd_indices_count);

        int total_count = (even_choices * odd_choices) % MOD;

        return total_count;
    }
};