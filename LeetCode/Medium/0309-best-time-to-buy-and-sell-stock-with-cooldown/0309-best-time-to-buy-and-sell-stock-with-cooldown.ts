function maxProfit(prices: number[]): number {
    const n = prices.length;
    if (n === 0) return 0;

    // 第一天初始化
    let hold = -prices[0]; // 持有
    let rest = 0;          // 可买(不持有、非冷冻)
    let cool = 0;          // 冷冻(刚卖出)

    for (let i = 1; i < n; i++) {
        const p = prices[i];
        const prevHold = hold, prevRest = rest, prevCool = cool;

        hold = Math.max(prevHold, prevRest - p);
        cool = prevHold + p;                 // 今天卖出 -> 冷冻
        rest = Math.max(prevRest, prevCool); // 冷冻结束或继续休息
    }
    return Math.max(rest, cool);
};