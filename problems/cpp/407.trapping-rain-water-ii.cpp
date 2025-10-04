#include <algorithm>

#include "leetcode.h"

class Solution {
    struct Block {
        int height;
        pair<int, int> coor;

        bool operator>(const Block& other) const {
            return height > other.height;
        }
    };

   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int water = 0;
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<Block, vector<Block>, greater<Block>> pq;

        // push all boundary block in the pq and mark as visited (-1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    heightMap[i][j] = -1;  // Mark as visited
                }
            }
        }

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // waterlevel is the height of the lowest boundary block in the area
        while (!pq.empty()) {
            auto bound = pq.top();
            pq.pop();

            // scan adjacent blocks
            for (auto& dir : dirs) {
                int r = bound.coor.first + dir[0];
                int c = bound.coor.second + dir[1];

                // Check if neighbor is valid and not visited
                if (r >= 0 && r < n && c >= 0 && c < m &&
                    heightMap[r][c] != -1) {
                    int adjacent_height = heightMap[r][c];

                    // If the boundary is higher than the adjacent block, it
                    // traps water.
                    water += max(0, bound.height - adjacent_height);

                    // Push the new block to the boundary. The new wall height
                    // is the max of the current wall or the block's own height.
                    pq.push({max(bound.height, adjacent_height), {r, c}});

                    // Mark as visited after processing
                    heightMap[r][c] = -1;
                }
            }
        }

        return water;
    }
};
