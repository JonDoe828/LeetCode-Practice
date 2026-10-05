class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    bool zero = dp[i][j - 2]; // x* 匹配 0 次
                    bool more = i >= 1 &&
                                (p[j - 2] == '.' || s[i - 1] == p[j - 2]) &&
                                dp[i - 1][j]; // x* 至少匹配 1 次（需要 i >= 1）
                    dp[i][j] = zero || more;

                } else {
                    dp[i][j] = i >= 1 && dp[i - 1][j - 1] &&
                               (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};