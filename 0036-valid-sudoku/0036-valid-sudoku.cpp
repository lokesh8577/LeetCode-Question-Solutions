class Solution {
private:
    bool check(int row, int col, vector<vector<char>>& board, int value) {
        // Row & Col Check
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] != '.' &&
                board[i][col] - '0' == value) {
                return false;
            }
            if (i != col && board[row][i] != '.' &&
                board[row][i] - '0' == value) {
                return false;
            }
        }

        // 3X3 Box Check
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);

        for (int i = 0; i < 9; i++) {
            int r = startRow + i / 3;
            int c = startCol + i % 3;

            if ((r != row || c != col) && board[r][c] != '.' &&
                board[r][c] - '0' == value) {
                return false;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int value = board[i][j] - '0';
                    if (!check(i, j, board, value)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};