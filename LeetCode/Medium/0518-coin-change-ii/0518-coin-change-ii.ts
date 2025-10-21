function change(amount: number, coins: number[]): number {
    const dp: number[] = Array(amount + 1).fill(0);
    dp[0] = 1;
    for (const c of coins) {
        for (let x = c; x <= amount; x++) {
            dp[x] += dp[x - c];
        }
    }
    return dp[amount];
};