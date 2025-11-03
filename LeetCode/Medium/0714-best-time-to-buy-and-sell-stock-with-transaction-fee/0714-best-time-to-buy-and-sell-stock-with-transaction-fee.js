/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
// var maxProfit = function (prices, fee) {
//     if (prices.length === 0) return 0;
//     let no = 0;            // 不持有
//     let hold = -prices[0]; // 持有
//     for (let i = 1; i < prices.length; i++) {
//         const prevNo = no;
//         no = Math.max(no, hold + prices[i] - fee);
//         hold = Math.max(hold, prevNo - prices[i]);
//     }
//     return no;
// };


var maxProfit = function (prices, fee) {
  if (prices.length === 0) return 0;
  let profit = 0;
  let buy = prices[0] + fee;      // 有效买入价
  for (let i = 1; i < prices.length; i++) {
    const p = prices[i];
    if (p + fee < buy) {
      buy = p + fee;              // 找到更低的入场价
    } else if (p > buy) {
      profit += p - buy;          // 卖出锁定利润
      buy = p;                    // 视作“马上换仓”，维持上升段继续吃
    }
  }
  return profit;
}