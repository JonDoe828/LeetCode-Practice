/**
 * @param {number[]} prices
 * @return {number}
 */

//2D DP
// var maxProfit = function (prices) {
//     const len = prices.length
//     if (len == 0) return 0
//     const dp = Array.from({ length: len }, () => [0, 0]);
//     dp[0][0] = - prices[0]
//     dp[0][1] = 0
//     for (let i = 1; i < len; i++) {
//         dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] - prices[i])
//         dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i])
//     }
//     return dp[len - 1][1]
// };

var maxProfit = function(prices) {
  let cash = 0, hold = -prices[0];
  for (let i = 1; i < prices.length; i++) {
    const newCash = Math.max(cash, hold + prices[i]);
    const newHold = Math.max(hold, cash - prices[i]);
    cash = newCash; hold = newHold;
  }
  return cash;
};

// var maxProfit = function (prices) {
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
// };