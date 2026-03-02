#include <unordered_map>
#include <utility>
using namespace std;

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        // Combine hashes (simple example, more robust methods exist)
        return h1 ^ (h2 << 1); 
    }
};

class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800)
            return 1;

        return p(n, n);
    }
private:
    unordered_map<pair<int, int>, double, PairHash> dp;
    double p(int a, int b) {
        if (a <= 0 && b <= 0)
            return 0.5;
        else if (a <= 0)
            return 1;
        else if (b <= 0)
            return 0;

        if (dp.count({a, b}))
            return dp[{a, b}];

        double result = p(a-100, b) + p(a-75, b-25) + p(a-50, b-50) + p(a-25, b-75);
        result /= 4;
        dp[{a, b}] = result;

        return result;
    }
};
