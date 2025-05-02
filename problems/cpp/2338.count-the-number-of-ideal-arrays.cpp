/*
 * @lc app=leetcode id=2338 lang=cpp
 *
 * [2338] Count the Number of Ideal Arrays
 */

// @lc code=start
#include <vector>
#include <numeric> // For std::iota (used in sieve)

using namespace std;

// --- 必要的輔助函式：模冪次和模逆元 ---
// (用來計算組合數 C(n, k) % MOD)

const int MOD = 1000000007; // 題目要求的模數 10^9 + 7

// 計算 (base^exp) % MOD
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// 計算 n 的模逆元 (使用費馬小定理，因為 MOD 是質數)
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// --- 預處理 1：組合數計算 ---
// (預先算好階乘和階乘的模逆元，方便快速計算 C(n, k))

vector<long long> fact;      // fact[i] = i! % MOD
vector<long long> invFact; // invFact[i] = (i!)^(-1) % MOD

// 預計算最大到 maxN 的階乘和模逆元
void precomputeCombinations(int maxN) {
    // 如果已經計算過且範圍足夠，就不用重算
    if (!fact.empty() && fact.size() >= maxN + 1) return;

    fact.resize(maxN + 1);
    invFact.resize(maxN + 1);
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= maxN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    // 一次性計算 invFact[maxN]，然後反推回來比較快
    invFact[maxN] = modInverse(fact[maxN]);
    for (int i = maxN - 1; i >= 1; --i) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// 計算 C(n, k) % MOD
long long nCr(int n, int r) {
    if (r < 0 || r > n) { // 不合法的參數
        return 0;
    }
    if (r == 0 || r == n) return 1; // C(n, 0) = C(n, n) = 1
    if (r > n / 2) r = n - r; // 優化：C(n, k) = C(n, n-k)

    // 確保預計算的範圍足夠
    if (n >= fact.size()) {
        // 理論上 precomputeCombinations 應該已經處理好，這裡只是保險
        return 0; // 表示預計算不足
    }

    // C(n, k) = n! / (k! * (n-k)!)
    // C(n, k) = n! * (k!)^(-1) * ((n-k)!)^(-1) % MOD
    long long num = fact[n];
    long long den1 = invFact[r];
    long long den2 = invFact[n - r];

    return (((num * den1) % MOD) * den2) % MOD;
}


// --- 預處理 2：篩法找最小質因數 (SPF) ---
// (用來快速分解質因數 m，計算 v_p(m))

vector<int> spf; // spf[i] = i 的最小質因數 (Smallest Prime Factor)
vector<int> primes; // 儲存找到的質數 (雖然這裡沒直接用到，但篩法會產生)

// 線性篩法，計算 1 到 n 的最小質因數
void sieve(int n) {
    // 如果已經計算過且範圍足夠，就不用重算
    if (!spf.empty() && spf.size() >= n + 1) return;

    spf.assign(n + 1, 0);
    iota(spf.begin(), spf.end(), 0); // 初始化 spf[i] = i
    primes.clear();

    for (int i = 2; i <= n; ++i) {
        if (spf[i] == i) { // i 是質數
            primes.push_back(i);
        }
        // 用已找到的質數 p 去篩掉 p*i
        for (int p : primes) {
            // 如果 p 比 i 的最小質因數還大，那 p*i 的最小質因數一定是 spf[i]，不是 p
            // 或是超出範圍就停止
            if (p > spf[i] || (long long)i * p > n) break;
            // p 是 i*p 的最小質因數
            spf[i * p] = p;
        }
    }
}


// --- 主解決函式 ---

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        // --- 步驟 0：處理 n=1 的特殊情況 ---
        if (n == 1) {
            return maxValue; // 只有 [a] 這種形式，a 可以是 1 到 maxValue
        }

        // --- 步驟 1：預處理 ---
        // 計算組合數最大需要到 C(E + n - 2, n - 2)
        // E 最大約 log2(maxValue)，所以 N 最大約 maxValue + n
        int maxCombN = maxValue + n;
        precomputeCombinations(maxCombN);

        // 篩法需要跑到 maxValue
        sieve(maxValue);

        // --- 步驟 2：計算總和 S = Sum [ ways(n, m) * floor(maxValue / m) ] ---
        long long totalSum = 0;

        // 遍歷所有可能的結尾 m (從 1 到 maxValue)
        for (int m = 1; m <= maxValue; ++m) {

            // --- 步驟 2a：計算 ways(n, m) ---
            // ways(n, m) = Product [ C(v_p(m) + n - 2, n - 2) ] for p | m
            long long ways_m = 1; // 初始化 ways(n, m)
            int temp_m = m;       // 用來分解質因數

            // 利用 SPF 快速分解質因數
            while (temp_m > 1) {
                int p = spf[temp_m]; // 取得最小質因數
                int exponent = 0;    // 計算 p 的次方 (v_p(m))
                while (temp_m > 1 && spf[temp_m] == p) { // 當最小質因數還是 p 時
                    exponent++;
                    temp_m /= p; // 把 p 除掉
                }

                // 計算這個質因數 p 的貢獻：C(E + n - 2, n - 2)
                long long combinations = nCr(exponent + n - 2, n - 2);

                // 乘到 ways_m 中 (記得取模)
                ways_m = (ways_m * combinations) % MOD;
            }
            // 分解完畢，ways_m 就是 ways(n, m) 的值

            // --- 步驟 2b：計算 m 的貢獻並加到總和 ---
            // 貢獻 = ways(n, m) * floor(maxValue / m)
            // C++ 整數除法 `maxValue / m` 自動就是 floor
            long long term = (ways_m * (maxValue / m)) % MOD;
            totalSum = (totalSum + term) % MOD;
        }

        // --- 步驟 3：返回結果 ---
        return (int)totalSum;
    }
};
// @lc code=end

