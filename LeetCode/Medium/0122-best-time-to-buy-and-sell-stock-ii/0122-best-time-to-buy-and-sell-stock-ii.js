/**
 * @param {number[]} prices
 * @return {number}
 */

//2D DP
//4 ms
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


//3ms
// var maxProfit = function(prices) {
//   let cash = 0, hold = -prices[0];
//   for (let i = 1; i < prices.length; i++) {
//     const newCash = Math.max(cash, hold + prices[i]);
//     const newHold = Math.max(hold, cash - prices[i]);
//     cash = newCash; hold = newHold;
//   }
//   return cash;
// };

//4 ms
// var maxProfit = function (prices) {
//   if (prices.length === 0) return 0;

//   let buy = prices[0], profit = 0;
//   for (let i = 1; i < prices.length; i++) {
//     // 若出现回落或持平，说明前一段上升结束，结算一次
//     if (prices[i] <= prices[i - 1]) {
//       profit += Math.max(0, prices[i - 1] - buy);
//       buy = prices[i]; // 新的谷底
//     }
//   }
//   // 补结最后一段上升
//   profit += Math.max(0, prices[prices.length - 1] - buy);
//   return profit;
// };


//0 ms
var maxProfit = function (prices) {
  if (prices.length === 0) return 0;

  let profit = 0;
  for (let i = 1; i < prices.length; i++) {
    if (prices[i] > prices[i - 1]) {
      profit += prices[i] - prices[i - 1]; // 吃下每一步的上涨
    }
  }
  return profit;
};