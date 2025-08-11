#include <queue>
#include <vector>

using namespace std;

namespace Dir {
    const int L = 0;
    const int R = 1;
}

class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int l = 0, r = costs.size()-1;
        
        // Cost, Dir, Index
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int i = 0; i < candidates && l <= r; i++) {
            pq.emplace(costs[l], Dir::L, l);
            l++;
        }

        for (int i = 0; i < candidates && l <= r; i++) {
            pq.emplace(costs[r], Dir::R, r);
            r--;
        }

        long long result = 0;
        while (k-- > 0 && !pq.empty()) {
            auto [cost, dir, index] = pq.top();
            pq.pop();
            result += cost;

            if (l <= r) {
                if (dir == Dir::L) {
                    pq.emplace(costs[l], Dir::L, l);
                    l++;
                } else {
                    pq.emplace(costs[r], Dir::R, r);
                    r--;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> costs = {1, 2, 4, 1};
    int k = 3;
    int candidates = 3;
    s.totalCost(costs, k, candidates);
}
