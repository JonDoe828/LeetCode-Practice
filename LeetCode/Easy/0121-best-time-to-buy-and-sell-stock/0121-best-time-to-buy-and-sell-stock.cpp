// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len = prices.size();
//         if (len == 0)
//             return 0;
//         vector<vector<int>> dp(len, vector<int>(2));
//         dp[0][0] -= prices[0];
//         dp[0][1] = 0;

//         for (int i = 1; i < len; i++) {
//             dp[i][0] = max(dp[i - 1][0], -prices[i]);
//             dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
//         }
//         return dp[len - 1][1];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(
            2, vector<int>(2)); // 注意这⾥只开辟了⼀个2 * 2⼤⼩的⼆维数组
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] =
                max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
        }
        return dp[(len - 1) % 2][1];
    }
};