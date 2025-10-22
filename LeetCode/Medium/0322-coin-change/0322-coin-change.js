/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
    if (amount === 0) return 0;

    const INF = amount + 1;
    const dp = new Array(amount + 1).fill(INF);
    dp[0] = 0;

    for (const c of coins) {
        for (let x = c; x <= amount; x++) {
            // 如果 dp[x - c] 仍是 INF，说明该状态不可达，此时 INF + 1 仍然安全
            dp[x] = Math.min(dp[x], dp[x - c] + 1);
        }
    }
    return dp[amount] === INF ? -1 : dp[amount];
};