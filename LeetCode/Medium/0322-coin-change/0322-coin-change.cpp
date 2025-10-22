class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) {       // 遍历物品
            for (int j = coins[i]; j <= amount; j++) { // 遍历背包
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};