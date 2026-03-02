class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, block[3][3][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';

                    if (row[i][num] || col[j][num] || block[i/3][j/3][num])
                        return false;
                    else {
                        row[i][num] = 1;
                        col[j][num] = 1;
                        block[i/3][j/3][num] = 1;
                    }
                }
            }
        }
        return true;
    }
};