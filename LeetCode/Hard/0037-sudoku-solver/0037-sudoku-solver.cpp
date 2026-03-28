class Solution {
public:
    bool rowUsed[9][10] = {};
    bool colUsed[9][10] = {};
    bool boxUsed[9][10] = {};

    bool backtracking(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col]!= '.')
                    continue;

                int box = (row / 3) * 3 + (col / 3);

                for (int k = 1; k <= 9; k++) {
                    if (!rowUsed[row][k] && !colUsed[col][k] && !boxUsed[box][k]) {
                        board[row][col] = k + '0';
                        rowUsed[row][k] = colUsed[col][k] = boxUsed[box][k] = true;
                        if (backtracking(board))
                            return true;
                        board[row][col] = '.';
                        rowUsed[row][k] = colUsed[col][k] = boxUsed[box][k] = false;
                    }
                }
                return false; 
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                int box = (i / 3) * 3 + (j / 3);
                rowUsed[i][num] = true;
                colUsed[j][num] = true;
                boxUsed[box][num] = true;
            }
        }

        backtracking(board);
        
    }
};


