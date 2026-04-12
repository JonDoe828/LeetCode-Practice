class Solution {
public:
    string path;
    int n;
    vector<string> res;

    void backtracking(int left, int right) {

        if (path.size() == n * 2) {
            res.push_back(path);
            return;
        }

        if (left < n) {
            path.push_back('(');
            backtracking(left + 1, right);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtracking(left, right + 1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        this->n = n;
        backtracking(0, 0);
        return res;
    }
};