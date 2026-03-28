// class Solution {
// public:
//     bool rowUsed[9][10] = {};
//     bool colUsed[9][10] = {};
//     bool boxUsed[9][10] = {};

//     bool backtracking(vector<vector<char>>& board) {
//         for (int row = 0; row < 9; row++) {
//             for (int col = 0; col < 9; col++) {
//                 if (board[row][col]!= '.')
//                     continue;

//                 int box = (row / 3) * 3 + (col / 3);

//                 for (int k = 1; k <= 9; k++) {
//                     if (!rowUsed[row][k] && !colUsed[col][k] && !boxUsed[box][k]) {
//                         board[row][col] = k + '0';
//                         rowUsed[row][k] = colUsed[col][k] = boxUsed[box][k] = true;
//                         if (backtracking(board))
//                             return true;
//                         board[row][col] = '.';
//                         rowUsed[row][k] = colUsed[col][k] = boxUsed[box][k] = false;
//                     }
//                 }
//                 return false; 
//             }
//         }
//         return true; 
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] == '.') continue;
//                 int num = board[i][j] - '0';
//                 int box = (i / 3) * 3 + (j / 3);
//                 rowUsed[i][num] = true;
//                 colUsed[j][num] = true;
//                 boxUsed[box][num] = true;
//             }
//         }

//         backtracking(board);
        
//     }
// };


class Solution {
private:
bool backtracking(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {        // Traverse rows
        for (int j = 0; j < board[0].size(); j++) { // Traverse columns
            if (board[i][j] == '.') {
                for (char k = '1'; k <= '9'; k++) { // Check if 'k' absolutely fits in cell (i, j)
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;           // Place 'k'
                        if (backtracking(board)) return true; // Return immediately if a valid configuration is found
                        board[i][j] = '.';         // Backtrack to undo 'k'
                    }
                }
                return false;  // If all numbers are tried and failed, return false
            }
        }
    }
    return true; // If no 'false' is returned during traversal, a valid configuration is found
}
bool isValid(int row, int col, char val, vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) { // Check if any duplicates exist in the row
        if (board[row][i] == val) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) { // Check if any duplicates exist in the column
        if (board[j][col] == val) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // Check if any duplicates exist in the 3x3 sub-grid
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val ) {
                return false;
            }
        }
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};