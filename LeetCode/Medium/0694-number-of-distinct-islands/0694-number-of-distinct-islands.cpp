class Solution {
public:
    vector<pair<int, int>> shape;
    set<vector<pair<int, int>>> shapes;

    void dfs(vector<vector<int>>& grid, int x, int y, int baseX, int baseY,
             vector<pair<int, int>>& shape) {
        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || x >= m || y < 0 || y >= n)
            return;
        if (grid[x][y] == 0)
            return;

        grid[x][y] = 0; // 标记访问过，直接淹掉

        shape.push_back({x - baseX, y - baseY});

        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int k = 0; k < 4; k++) {
            int nextX = x + dir[k][0];
            int nextY = y + dir[k][1];

            dfs(grid, nextX, nextY, baseX, baseY, shape);
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> shape; 
                    dfs(grid, i, j, i, j, shape); 
                    shapes.insert(shape);
                }
            }
        }
        return shapes.size();
    }
};