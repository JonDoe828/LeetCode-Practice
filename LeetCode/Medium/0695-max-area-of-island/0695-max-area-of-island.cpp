class Solution {
public:
    int result = 0;
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return 0;
        if (grid[x][y] == 0)
            return 0;

        grid[x][y] = 0;
        return 1 + dfs(grid, x + 1, y) + dfs(grid, x - 1, y) +
               dfs(grid, x, y + 1) + dfs(grid, x, y - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    result = max(result, area);
                }
            }
        }
        return result;
    }
};