#include <queue>
#include <vector>

#include "leetcode.h"

class Solution {
    enum State { NOT_YET, READY, VISITED };

    struct Block {
        int height;
        pair<int, int> coor;

        bool operator>(const Block& other) const {
            return this->height > other.height;
        }
    };

   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<State>> grid_state(n, vector<State>(n, NOT_YET));

        priority_queue<Block, vector<Block>, greater<Block>> pq;
        pq.push({grid[n - 1][n - 1], {n - 1, n - 1}});
        grid_state[n - 1][n - 1] = VISITED;
        int answer = grid[n - 1][n - 1];

        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            Block current_block = pq.top();
            pq.pop();

            int row = current_block.coor.first;
            int col = current_block.coor.second;

            grid_state[row][col] = VISITED;
            answer = max(answer, current_block.height);

            if (row == 0 && col == 0)
                return answer;

            for (const auto& dir : dirs) {
                int row = current_block.coor.first + dir[0];
                int col = current_block.coor.second + dir[1];

                if (row >= n || row < 0 || col < 0 || col >= n ||
                    grid_state[row][col] != NOT_YET)
                    continue;

                pq.push({grid[row][col], {row, col}});
                grid_state[row][col] = READY;
            }
        }

        return answer;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    s.swimInWater(grid);
}
