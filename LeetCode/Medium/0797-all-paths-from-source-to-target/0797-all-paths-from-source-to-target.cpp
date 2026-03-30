class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<vector<int>>& graph, int x) {
        int n = graph.size();
        if (x == n - 1) {
            res.push_back(path);
            return;
        }

        for (int next : graph[x]) {
            path.push_back(next);
            dfs(graph, next);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return res;
    }
};