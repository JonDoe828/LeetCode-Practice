class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        vector<int> minDist(n, INT_MAX); // 最小距离
        vector<bool> inMST(n, false);    // 生成树合集

        minDist[0] = 0;

        long long result = 0;

        for (int i = 0; i < n; ++i) {
            // 1) 选一个当前未加入MST且minDist最小的点
            int cur = -1; // 哨兵值
            int curMin = INT_MAX;
            for (int v = 0; v < n; ++v) {
                if (!inMST[v] && minDist[v] < curMin) {
                    curMin = minDist[v];
                    cur = v;
                }
            }

            // 2) cur 一定能选到（完全图一定连通）
            inMST[cur] = true;
            result += curMin;

            // 3) 用cur去更新其他点到MST的最小距离（最小边权）
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int w = abs(points[cur][0] - points[v][0]) +
                            abs(points[cur][1] - points[v][1]);
                    if (w < minDist[v]) {
                        minDist[v] = w;
                    }
                }
            }
        }
        return (int)result;
    }
};