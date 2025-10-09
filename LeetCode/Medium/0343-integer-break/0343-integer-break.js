/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function (n) {
    const dp = Array(n + 1).fill(0);
    dp[2] = 1;

    for (let i = 3; i <= n; i++) {
        let best = 0;
        for (let j = 1; j < i; j++) {
            // either stop splitting right side, or keep splitting it
            best = Math.max(best, j * (i - j), j * dp[i - j]);
        }
        dp[i] = best;
    }
    return dp[n];
};