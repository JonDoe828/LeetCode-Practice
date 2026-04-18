class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        const int INF = 1e9;
        vector<vector<int>> dp(k + 2, vector<int>(n, INF));

        dp[0][src] = 0;

        for (int i = 1; i <= k + 1; i++) {
            dp[i] = dp[i - 1];

            for (auto& flight : flights) {
                int f = flight[0];
                int t = flight[1];
                int p = flight[2];

                if (dp[i - 1][f] != INF) {
                    dp[i][t] = min(dp[i][t], dp[i - 1][f] + p);
                }
            }
        }

        return dp[k + 1][dst] == INF ? -1 : dp[k + 1][dst];
    }
};