class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(const vector<int>& n, int startIndex) {
        if (path.size() >= 2) {
            res.push_back(path);
        }

        unordered_set<int> used;
        for (int i = startIndex; i < n.size(); i++) {

            if (used.find(n[i]) != used.end()) {
                continue;
            }
            used.insert(n[i]);

            if (!path.empty() && n[i] < path.back()) {
                continue;
            }

            path.push_back(n[i]);
            backtracking(n, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};