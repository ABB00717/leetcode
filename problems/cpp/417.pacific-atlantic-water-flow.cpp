#include <vector>
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> can_reach_paci(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_atla(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(heights, can_reach_paci, i, 0);
            dfs(heights, can_reach_atla, i, n - 1);
        }

        for (int j = 0; j < n; ++j) {
            dfs(heights, can_reach_paci, 0, j);
            dfs(heights, can_reach_atla, m - 1, j);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (can_reach_paci[i][j] && can_reach_atla[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& can_reach, int row, int col) {
        if (can_reach[row][col]) {
            return;
        }
        can_reach[row][col] = true;

        int m = heights.size();
        int n = heights[0].size();
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && heights[nr][nc] >= heights[row][col]) {
                dfs(heights, can_reach, nr, nc);
            }
        }
    }
};
