/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
var maxProfit = function (prices, fee) {
    if (prices.length === 0) return 0;
    let no = 0;            // 不持有
    let hold = -prices[0]; // 持有
    for (let i = 1; i < prices.length; i++) {
        const prevNo = no;
        no = Math.max(no, hold + prices[i] - fee);
        hold = Math.max(hold, prevNo - prices[i]);
    }
    return no;
};