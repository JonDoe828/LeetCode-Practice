/**
 * @param {number[]} prices
 * @return {number}
 */

//2D DP
var maxProfit = function (prices) {
    const len = prices.length
    if (len == 0) return 0
    const dp = Array.from({ length: len }, () => [0, 0]);
    dp[0][0] = - prices[0]
    dp[0][1] = 0
    for (let i = 1; i < len; i++) {
        dp[i][0] = Math.max(dp[i - 1][0], -prices[i])
        dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i])
    }
    return dp[len - 1][1]
};


// var maxProfit = function (prices) {
//     let hold = -Infinity; // 持有状态（最多买一次）：相当于 -minPrice
//     let cash = 0;         // 不持有状态（已经卖出或从未买）

//     for (const p of prices) {
//         hold = Math.max(hold, -p);   // 选择在更低价买入
//         cash = Math.max(cash, hold + p); // 选择在今天卖出
//     }
//     return cash;
// };



// const maxProfit = (prices) => {
//     if (prices.length === 0) return 0;

//     let buy = prices[0];
//     let profit = 0;
//     for (let i = 1; i < prices.length; i++) {
//         if (prices[i] < buy) {
//             buy = prices[i];
//         } else if (prices[i] - buy > profit) {
//             profit = prices[i] - buy;
//         }
//     }
//     return profit;
// }

