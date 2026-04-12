class Solution {
public:
    string path;

    vector<string> res;

    void backtracking(int left, int right, int n) {

        if (path.size() == n * 2) {
            res.push_back(path);
            return;
        }

        if (left < n) {
            path.push_back('(');
            backtracking(left + 1, right, n);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtracking(left, right + 1, n);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtracking(0, 0, n);
        return res;
    }
};