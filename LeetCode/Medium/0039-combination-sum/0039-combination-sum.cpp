class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& candidates, int target, int sum,
                      int startIndex) {

        if (sum > target)
            return;

        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {

            path.push_back(candidates[i]);
            sum += candidates[i];

            backtracking(candidates, target, sum, i); // 关键：i 不是 i+1

            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};