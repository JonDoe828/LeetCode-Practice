class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        vector<long long> dp(n + 1), g(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        // g[0] = 0, g[1] = 1 其实可以让递推自己推出来，这里从 2 开始循环即可
        for (int i = 2; i <= n; ++i) {
            // 有缺口的情况
            g[i] = (dp[i - 2] + g[i - 1]) % MOD;
            // 完全铺满的情况
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * g[i - 1]) % MOD;
        }

        return (int)dp[n];
    }
};