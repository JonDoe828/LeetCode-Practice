class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;

        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (char c : instructions) {
            if (c == 'G') {
                x += d[dir][0];
                y += d[dir][1];
            } else if (c == 'L') {
                dir = (dir + 3) % 4;
            } else if (c == 'R') {
                dir = (dir + 1) % 4;
            }
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};