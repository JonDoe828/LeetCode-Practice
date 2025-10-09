function integerBreak(n: number): number {
    const dp: number[] = Array(n + 1).fill(0);
    if (n >= 2) dp[2] = 1;

    for (let i = 3; i <= n; i++) {
        let best = 0;
        for (let j = 1; j < i; j++) {
            best = Math.max(best, j * (i - j), j * dp[i - j]);
        }
        dp[i] = best;
    }
    return dp[n];
};