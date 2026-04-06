class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, dir = 0, ans = 0;
        set<pair<int, int>> obs;

        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& p : obstacles) {
            obs.insert({p[0], p[1]});
        }

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                dir = (dir + 1) % 4;
            } else if (commands[i] == -2) {
                dir = (dir + 3) % 4;
            } else {
                int step = commands[i];
                for (int j = 0; j < step; j++) {
                    int nx = x + d[dir][0];
                    int ny = y + d[dir][1];

                    if (obs.count({nx, ny})) {
                        break;
                    }

                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};