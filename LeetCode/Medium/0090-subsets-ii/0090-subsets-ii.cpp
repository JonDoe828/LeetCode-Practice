class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(const vector<int>& n, int startIndex) {
        res.push_back(path);

        for (int i = startIndex; i < n.size(); i++) {

            if (i > startIndex && n[i] == n[i - 1])
                continue;
            path.push_back(n[i]);
            backtracking(n, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
};