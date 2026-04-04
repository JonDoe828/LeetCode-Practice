class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
            return;
        }
        if (grid[x][y] == 0) {
            return;
        }

        grid[x][y] = 0;

        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        dfs(grid, x, y - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0); // 左边界
            if (grid[i][n - 1] == 1)
                dfs(grid, i, n - 1); // 右边界
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1)
                dfs(grid, 0, j); // 上边界
            if (grid[m - 1][j] == 1)
                dfs(grid, m - 1, j); // 下边界
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};