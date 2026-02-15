// Kruskal
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(),
             [](const auto& a, const auto& b) { return a[2] < b[2]; });

        vector<int> parent(n + 1), rankv(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;

        auto find = [&](auto&& self, int x) -> int {
            if (parent[x] != x)
                parent[x] = self(self, parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) -> bool {
            int pa = find(find, a), pb = find(find, b);
            if (pa == pb)
                return false;
            if (rankv[pa] < rankv[pb])
                swap(pa, pb);
            parent[pb] = pa;
            if (rankv[pa] == rankv[pb])
                rankv[pa]++;
            return true;
        };

        long long cost = 0;
        int used = 0;
        for (auto& e : connections) {
            if (unite(e[0], e[1])) {
                cost += e[2];
                used++;
                if (used == n - 1)
                    break;
            }
        }
        return used == n - 1 ? (int)cost : -1;
    }
};

// Prim
// class Solution {
// public:
//     int minimumCost(int n, vector<vector<int>>& connections) {
//         // 建邻接矩阵 超时
//         vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
//         for (auto& e : connections) {
//             int u = e[0], v = e[1], w = e[2];
//             grid[u][v] = w;
//             grid[v][u] = w;
//         }

//         vector<int> minDist(n + 1, INT_MAX);
//         vector<bool> inMST(n + 1, false);

//         minDist[1] = 0;
//         int result = 0;

//         for (int i = 1; i <= n; i++) {
//             int cur = -1;
//             int minVal = INT_MAX;
//             // 1. 非生成树距离生成树最近节点cur
//             for (int v = 1; v <= n; v++) {
//                 if (!inMST[v] && minDist[v] < minVal) {
//                     minVal = minDist[v];
//                     cur = v;
//                 }
//             }

//             // 如果选不到 → 不连通
//             if (cur == -1)
//                 return -1;

//             // 2. 将cur加入生成树
//             inMST[cur] = true;
//             result += minVal;

//             // 3. 更新所有非生成树节点到生成树的距离
//             for (int j = 1; j <= n; j++) {
//                 if (!inMST[j] && grid[cur][j] < minDist[j]) {
//                     minDist[j] = grid[cur][j];
//                 }
//             }
//         }

//         return result;
//     }
// };

// Prim+邻接表+堆优化
// class Solution {
// public:
//     int minimumCost(int n, vector<vector<int>>& connections) {
//         using P = pair<int,int>; // (weight, node)

//         vector<vector<pair<int,int>>> adj(n + 1);
//         for (auto &e : connections) {
//             int u = e[0], v = e[1], w = e[2];
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }

//         vector<bool> inMST(n + 1, false);
//         priority_queue<P, vector<P>, greater<P>> pq;

//         // 从1开始
//         pq.push({0, 1});

//         long long cost = 0;
//         int picked = 0;

//         while (!pq.empty() && picked < n) {
//             auto [w, u] = pq.top();
//             pq.pop();

//             if (inMST[u]) continue;

//             inMST[u] = true;
//             cost += w;
//             picked++;

//             for (auto [v, w2] : adj[u]) {
//                 if (!inMST[v]) pq.push({w2, v});
//             }
//         }

//         return picked == n ? (int)cost : -1;
//     }
// };


