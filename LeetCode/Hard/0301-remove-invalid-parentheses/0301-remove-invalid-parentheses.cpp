class Solution {
public:
    string s;
    unordered_set<string> res;
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        int left = 0, right = 0;
        for (auto& brackets : s) {
            if (brackets == '(') {
                left++;
            } else if (brackets == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        string path;
        backtrack(0, left, right, 0, true, path);
        return vector<string>(res.begin(), res.end());
    }

    void backtrack(int idx, int left, int right, int open, bool prevDeleted,
                   string& path) {
        if (left + right > s.size() - idx) // 优化二：剪枝
            return;

        if (idx == s.size()) {
            if (left == 0 && right == 0 && open == 0) {
                res.insert(path);
            }
            return;
        }

        char c = s[idx];

        // 能删的前提：是这串的第一个，或者前一个相同字符也删了
        bool canDelete = (idx == 0 || s[idx] != s[idx - 1] || prevDeleted);

        // 选择一：删掉 c（只对括号，且还有预算）
        if (c == '(' && left > 0) {
            backtrack(idx + 1, left - 1, right, open, true, path);
        }
        if (c == ')' && right > 0) {
            backtrack(idx + 1, left, right - 1, open, true, path);
        }

        // 选择二：保留 c
        path.push_back(c);

        if (c == '(') {
            backtrack(idx + 1, left, right, open + 1, false, path);
        } else if (c == ')') {
            if (open > 0)
                backtrack(idx + 1, left, right, open - 1, false,
                          path); // 有 '(' 可配才能留
        } else {
            backtrack(idx + 1, left, right, open, false, path); // 字母直接留
        }
        path.pop_back();
    }
};