class Solution {
public:
    int count = 0;

    void bfs(vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});
        grid[x][y] = '0';

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!que.empty()) {
            int curX = que.front().first;
            int curY = que.front().second;
            que.pop();

            for (int i = 0; i < 4; i++) {
                int nextX = curX + dir[i][0];
                int nextY = curY + dir[i][1];

                if (nextX < 0 || nextX >= grid.size() || nextY < 0 ||
                    nextY >= grid[0].size()) {
                    continue;
                }

                if (grid[nextX][nextY] == '1') {
                    que.push({nextX, nextY});
                    grid[nextX][nextY] = '0'; 
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
   
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }

        return count;
    }
};