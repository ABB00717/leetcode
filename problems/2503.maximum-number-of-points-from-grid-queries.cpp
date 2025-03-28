/*
 * @lc app=leetcode id=2503 lang=cpp
 *
 * [2503] Maximum Number of Points From Grid Queries
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int qlen = queries.size();

        vector<pair<int, int>> sortedQueries(qlen);
        for (int i = 0; i < qlen; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> maxHeap;
        maxHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> res(qlen);
        int count = 0;
        
        for (int i = 0; i < qlen; i++) {
            int idx = sortedQueries[i].second;
            int query = sortedQueries[i].first;

            while (!maxHeap.empty() && get<0>(maxHeap.top()) < query) {
                auto [val, r, c] = maxHeap.top();
                maxHeap.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d][0], nc = c + dirs[d][1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc])
                        continue;
                    visited[nr][nc] = true;
                    maxHeap.push({grid[nr][nc], nr, nc});
                }
                
                count++;
            }
            
            res[idx] = count;
        }

        return res;
    }
};

// @lc code=end
