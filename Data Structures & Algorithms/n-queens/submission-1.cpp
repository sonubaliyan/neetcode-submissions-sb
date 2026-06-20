class Solution {
public:
    vector<vector<string>> res;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check column
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check left diagonal, move diagonally up left side.
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check right diagonal, move diagonally up right side.
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backtrack(vector<string>& board, int row, int n) {

        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                backtrack(board, row + 1, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        backtrack(board, 0, n);

        return res;
    }
};