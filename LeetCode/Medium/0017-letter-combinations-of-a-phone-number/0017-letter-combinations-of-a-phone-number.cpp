class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        static const vector<string> mp = {"",    "",    "abc",  "def", "ghi",
                                          "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        string path;
        path.reserve(digits.size());

        function<void(int)> dfs = [&](int idx) {
            if (idx == (int)digits.size()) {
                res.push_back(path);
                return;
            }
            int d = digits[idx] - '0';
            const string& letters = mp[d];
            for (char c : letters) {
                path.push_back(c);
                dfs(idx + 1);
                path.pop_back(); // 回溯：撤销本次选择
            }
        };

        dfs(0);
        return res;
    }
};