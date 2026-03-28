class Solution {
public:
    vector<string> board;
    vector<vector<string>> res;
    vector<bool> col, diag1, diag2;

    void backtracking(int n, int row) {

        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (col[i] || diag1[row - i + n - 1] || diag2[row + i]) {
                continue;
            }

            board[row][i] = 'Q';
            col[i] = true;
            diag1[row - i + n - 1] = true;
            diag2[row + i] = true;

            backtracking(n, row + 1);
            board[row][i] = '.';
            col[i] = false;
            diag1[row - i + n - 1] = false;
            diag2[row + i] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);
        backtracking(n, 0);
        return res;
    }
};