// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> a(n + 2, 1);
//         for (int i = 0; i < n; i++)
//             a[i + 1] = nums[i];

//         vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
//         for (int len = 2; len <= n + 1; len++) {
//             for (int i = 0; i + len <= n + 1; i++) {
//                 int j = i + len;
//                 for (int k = i + 1; k < j; k++) {
//                     dp[i][j] =
//                         max(dp[i][j], dp[i][k] + a[i] * a[k] * a[j] + dp[k][j]);
//                 }
//             }
//         }
//         return dp[0][n + 1];
//     }
// };



class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> a = {1};
        for (int x : nums) if (x > 0) a.push_back(x);   // 去掉 0
        a.push_back(1);
        int m = a.size();

        static int dp[302][302], dt[302][302];          // dt[j][k] = dp[k][j]
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++) dp[i][j] = dt[i][j] = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 2; j < m; j++) {
                int ij = a[i] * a[j], best = 0;
                for (int k = i + 1; k < j; k++) {
                    int v = dp[i][k] + dt[j][k] + ij * a[k];
                    if (v > best) best = v;
                }
                dp[i][j] = best;
                dt[j][i] = best;
            }
        }
        return dp[0][m - 1];
    }
};