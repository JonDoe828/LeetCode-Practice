// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size(), n = text2.size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                 if (text1[i - 1] == text2[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//         return dp[m][n];
//     }
// };


class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> dp(n + 1, 0);   // dp[j] 表示“上一行的 dp[i-1][j]”，会被就地更新成当前行
        for (int i = 1; i <= m; ++i) {
            int prev = 0;           // 保存“左上角”的 dp[i-1][j-1]
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];   // 先存“上方”的 dp[i-1][j]，供下一步 prev 使用
                if (a[i - 1] == b[j - 1]) {
                    dp[j] = prev + 1;          // 来自左上角 + 1
                } else {
                    dp[j] = max(dp[j], dp[j - 1]); // max(上方, 左方)
                }
                prev = temp;        // 更新左上角，进入下一个 j
            }
        }
        return dp[n];
    }
};