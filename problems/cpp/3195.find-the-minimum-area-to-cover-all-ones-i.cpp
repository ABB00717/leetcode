#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // min, MAX
        pair<int, int> row = {INT_MAX, 0}, col = {INT_MAX, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    col.first = min(col.first, j);
                    row.first = min(row.first, i);
                    col.second = max(col.second, j);
                    row.second = max(row.second, i);
                }
            }
        }

        return (row.second - row.first + 1) * (col.second - col.first + 1);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{0,1,0},{1,0,1}};
    solution.minimumArea(grid);
}
