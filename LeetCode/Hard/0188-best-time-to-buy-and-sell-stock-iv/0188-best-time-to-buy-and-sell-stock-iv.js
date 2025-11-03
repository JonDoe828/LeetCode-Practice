/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (k, prices) {
    const n = prices.length;
    if (n === 0 || k === 0) return 0;

    // 大 k 特判：相当于无限次交易
    if (k >= Math.floor(n / 2)) {
        let ans = 0;
        for (let i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
        }
        return ans;
    }

    const dp = Array.from({ length: n }, () => new Array(2 * k + 1).fill(0));
    // 初始化：所有奇数位（买入态）设为 -prices[0]
    for (let j = 1; j < 2 * k; j += 2) dp[0][j] = -prices[0];

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < 2 * k - 1; j += 2) {
            // 买入态：保持 or 从上一个偶数位买入
            dp[i][j + 1] = Math.max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
            // 卖出态：保持 or 从买入态卖出
            dp[i][j + 2] = Math.max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
        }
    }
    return dp[n - 1][2 * k];
};