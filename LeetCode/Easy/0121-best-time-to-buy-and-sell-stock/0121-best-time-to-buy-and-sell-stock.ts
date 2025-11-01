function maxProfit(prices: number[]): number {
    if (prices.length === 0) return 0;

    let buy = prices[0];
    let profit = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] < buy) {
            buy = prices[i];
        } else if (prices[i] - buy > profit) {
            profit = prices[i] - buy;
        }
    }
    return profit;
};


// export function maxProfit(prices: number[]): number {
//   if (prices.length === 0) return 0;

//   let minPrice = prices[0];
//   let best = 0;

//   for (let i = 1; i < prices.length; i++) {
//     minPrice = Math.min(minPrice, prices[i]);
//     best = Math.max(best, prices[i] - minPrice);
//   }
//   return best;
// }