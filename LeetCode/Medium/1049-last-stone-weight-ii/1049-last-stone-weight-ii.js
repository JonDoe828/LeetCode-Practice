/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeightII = function (stones) {
    const sum = stones.reduce((a, b) => a + b, 0)
    const target = Math.floor(sum / 2); // 只取一半及以下
    const dp = new Array(target + 1).fill(false);
    dp[0] = true;

    for (const x of stones) {
        for (let w = target; w >= x; w--) {
            dp[w] = dp[w] || dp[w - x];
        }
    }

    for (let s = target; s >= 0; s--) {
        if (dp[s]) return sum - 2 * s;
    }
    return 0;
};