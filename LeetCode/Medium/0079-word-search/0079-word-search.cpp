class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int x, int y,
             int index) {

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }
        if (board[x][y] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }

        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        char temp = board[x][y];
        board[x][y] = '#';

        for (int k = 0; k < 4; k++) {
            int nextX = x + dir[k][0];
            int nextY = y + dir[k][1];

            if (dfs(board, word, nextX, nextY, index + 1)) {
                board[x][y] = temp;
                return true;
            }
        }

        board[x][y] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};