/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */

// @lc code=start
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        using PII = pair<long long, int>;

        vector<vector<pair<int, int>>> graph(n);
        for (const auto& r : roads) {
            int u = r[0], v = r[1], w = r[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<PII, vector<PII>, greater<PII>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cur_dist, u] = pq.top();
            pq.pop();

            if (cur_dist > dist[u])
                continue;
            
            for (auto [v, w] : graph[u]) {
                long long new_dist = dist[u] + w;
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    ways[v] = ways[u];
                    pq.push({new_dist, v});
                } else if (new_dist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
    
        return ways[n - 1];
    }
};

// @lc code=end
