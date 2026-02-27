class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int k, int n, int startIndex, int sum) {
        if (path.size() == k) {
            if (sum == n)
                result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);

            backtracking(k, n, i + 1, sum);

            sum -= i;        // 回溯
            path.pop_back(); // 撤销
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(k, n, 1, 0);
        return result;
    }
};