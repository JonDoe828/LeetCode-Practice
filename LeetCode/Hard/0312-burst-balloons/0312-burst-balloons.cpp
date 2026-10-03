class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++)
            a[i + 1] = nums[i];

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len <= n + 1; len++) {
            for (int i = 0; i + len <= n + 1; i++) {
                int j = i + len;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] =
                        max(dp[i][j], dp[i][k] + a[i] * a[k] * a[j] + dp[k][j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};