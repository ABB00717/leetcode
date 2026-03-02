#include <queue>
#include <vector>

using namespace std;

enum class OrangeState : int {
    Empty = 0,
    Fresh = 1,
    Rotten = 2
};

struct Coordinate {
    int row;
    int col;
};

struct Cell {
    int row;
    int col;
    int minute;
};

const vector<Coordinate> coordinates = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void initializeQueueAndCounts(const vector<vector<int>>& grid, queue<Cell>& to_rotten, int& total_orange) {
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            const int &current_grid = grid[i][j];
            if (current_grid == static_cast<int>(OrangeState::Empty))
                continue;

            total_orange++;
            if (current_grid == static_cast<int>(OrangeState::Rotten)) {
                to_rotten.push({i, j, 0});
            }
        }
    }
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Cell> to_rotten;
        int rotten_amount = 0;
        int total_orange = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        initializeQueueAndCounts(grid, to_rotten, total_orange);

        rotten_amount = to_rotten.size();
        int last_minute = 0;

        // BFS
        while (!to_rotten.empty()) {
            Cell current = to_rotten.front();
            last_minute = current.minute;
            to_rotten.pop();

            for (const auto& cor : coordinates) {
                Coordinate next = {current.row + cor.row, current.col + cor.col};
                if (next.row < 0 || next.row >= rows || next.col < 0 || next.col >= cols)
                    continue;
                if (grid[next.row][next.col] == static_cast<int>(OrangeState::Fresh)) {
                    grid[next.row][next.col] = static_cast<int>(OrangeState::Rotten);
                    rotten_amount++;
                    to_rotten.push({next.row, next.col, last_minute + 1});
                }
            }
        }

        if (rotten_amount != total_orange)
            return -1;

        return last_minute;
    }
};
