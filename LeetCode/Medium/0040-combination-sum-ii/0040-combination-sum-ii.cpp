class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& candidates, int target, int sum,
                      int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            // 剪枝
            if (sum + candidates[i] > target)
                break;

            // 同一层去重
            if (i > startIndex && candidates[i] == candidates[i - 1])
                continue;

            path.push_back(candidates[i]);
            backtracking(candidates, target, sum + candidates[i],
                         i + 1); // 每个元素只能用一次
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};