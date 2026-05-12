class Solution {
public:
    string path;
    vector<string> res;

    void backtracking(int n, int left, int right) {
        if (path.size() == n * 2) {
            res.push_back(path);
        }

        if (left < n) {
            path.push_back('(');
            backtracking(n, left + 1, right);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtracking(n, left, right + 1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtracking(n, 0, 0);
        return res;
    }
};