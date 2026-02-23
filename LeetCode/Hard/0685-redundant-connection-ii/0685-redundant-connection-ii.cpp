class Solution {
public:
    int find(int u, vector<int>& parent) {
        if (parent[u] != u)
            parent[u] = find(parent[u], parent);
        return parent[u];
    }

    bool unionSet(int u, int v, vector<int>& parent) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu == pv)
            return false; // 成环
        parent[pv] = pu;
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        vector<int> indegree(n + 1, 0);
        int cand1 = -1, cand2 = -1;

        // 1️⃣ 找入度为2的节点
        for (int i = 0; i < n; i++) {
            indegree[edges[i][1]]++;
            if (indegree[edges[i][1]] == 2) {
                cand2 = i;
                for (int j = 0; j < i; j++) {
                    if (edges[j][1] == edges[i][1]) {
                        cand1 = j;
                        break;
                    }
                }
                break;
            }
        }

        // 2️⃣ 如果有入度2情况
        if (cand2 != -1) {
            for (int i = 0; i < n; i++)
                parent[i + 1] = i + 1;

            for (int i = 0; i < n; i++) {
                if (i == cand2)
                    continue;
                if (!unionSet(edges[i][0], edges[i][1], parent))
                    return edges[cand1];
            }
            return edges[cand2];
        }

        // 3️⃣ 纯环情况
        for (int i = 0; i < n; i++) {
            if (!unionSet(edges[i][0], edges[i][1], parent))
                return edges[i];
        }

        return {};
    }
};