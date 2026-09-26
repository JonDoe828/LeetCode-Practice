class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        vector<double> ans;

        // 1. build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // 2. queries
        for (int i = 0; i < queries.size(); i++) {
            string start = queries[i][0];
            string end = queries[i][1];

            if (graph.find(start) == graph.end() ||
                graph.find(end) == graph.end()) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;

            double res = dfs(start, end, 1.0, visited);

            ans.push_back(res);
        }

        return ans;
    }

    double dfs(string cur, string target, double product,
               unordered_set<string>& visited) {
        if (cur == target)
            return product;

        visited.insert(cur);

        for (auto& [next, weight] : graph[cur]) {

            if (visited.count(next))
                continue;

            double res = dfs(next, target, product * weight, visited);

            if (res != -1.0)
                return res;
        }

        return -1.0;
    }
};