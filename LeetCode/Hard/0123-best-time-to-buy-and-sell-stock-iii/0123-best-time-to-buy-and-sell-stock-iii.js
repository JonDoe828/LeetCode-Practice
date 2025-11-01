/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    if (prices.length < 2) return 0;

    let hold1 = Number.NEGATIVE_INFINITY;
    let sold1 = 0;
    let hold2 = Number.NEGATIVE_INFINITY;
    let sold2 = 0;

    for (const p of prices) {
        hold1 = Math.max(hold1, -p);
        sold1 = Math.max(sold1, hold1 + p);
        hold2 = Math.max(hold2, sold1 - p);
        sold2 = Math.max(sold2, hold2 + p);
    }
    return sold2;
};