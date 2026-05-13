class Solution {
public:
    bool dfs(int cur, vector<vector<int>>& graph, vector<int>& color) {

        for (int enemy : graph[cur]) {
            if (color[enemy] == 0) {
                color[enemy] = -color[cur];
                if (!dfs(enemy, graph, color))
                    return false;
            } else if (color[enemy] == color[cur]) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0);
        vector<vector<int>> graph(n + 1);

        for (auto& d : dislikes) {
            int a = d[0];
            int b = d[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                if (!dfs(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};