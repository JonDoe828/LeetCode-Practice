class Solution {
public:
    // int minDistance(string word1, string word2) {
    //     int n = word1.size(), m = word2.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //     for (int i = 0; i <= n; ++i)
    //         dp[i][0] = i;
    //     for (int j = 0; j <= m; ++j)
    //         dp[0][j] = j;
    //     for (int i = 1; i <= n; ++i) {
    //         for (int j = 1; j <= m; ++j) {
    //             if (word1[i - 1] == word2[j - 1])
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             else
    //                 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
    //         }
    //     }
    //     return dp[n][m];
    // }

    // int minDistance(string s, string t) {
    //     int n = s.size(), m = t.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //     for (int i = 1; i <= n; ++i) {
    //         dp[i][0] = i; // 顺手设第0列
    //         for (int j = 1; j <= m; ++j) {
    //             dp[0][j] = j;
    //             if (s[i - 1] == t[j - 1])
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             else
    //                 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
    //         }
    //     }
    //     return dp[n][m];
    // }

    int minDistance(string& word1, string& word2) {
        if (size(word1) < size(word2))
            swap(word1, word2);
        vector<vector<int>> dp(2, vector<int>(size(word2) + 1));
        for (int i = 0; i <= size(word1); i++)
            for (int j = 0; j <= size(word2); j++)
                if (!i || !j)
                    dp[i & 1][j] = i + j;
                else
                    dp[i & 1][j] =
                        word1[i - 1] == word2[j - 1]
                            ? dp[(i - 1) & 1][j - 1]
                            : 1 + min(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
        return dp[size(word1) & 1][size(word2)];
    }
};