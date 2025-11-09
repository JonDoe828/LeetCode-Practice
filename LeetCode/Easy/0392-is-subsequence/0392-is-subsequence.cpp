// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int m = s.size(), n = t.size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         for (int i = 1; i <= m; ++i) {
//             for (int j = 1; j <= n; ++j) {
//                 if (s[i - 1] == t[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 } else {
//                     dp[i][j] = dp[i][j - 1];
//                 }
//             }
//         }
//         return dp[m][n] == m;
//     }
// };


//双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < (int)s.size() && j < (int)t.size()) {
            if (s[i] == t[j]) ++i;
            ++j;
        }
        return i == (int)s.size();
    }
};