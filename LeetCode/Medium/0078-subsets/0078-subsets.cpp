class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(const vector<int>& n, int startIndex) {

        res.push_back(path);

        for (int i = startIndex; i < n.size(); i++) {
            path.push_back(n[i]);
            backtracking(n, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};