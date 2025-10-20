function lastStoneWeightII(stones: number[]): number {
    const sum = stones.reduce((a, b) => a + b, 0)
    const target = Math.floor(sum / 2);
    const dp: number[] = new Array(target + 1).fill(0);

    for (let i = 0; i < stones.length; i++) {
        for (let j = target; j >= stones[i]; j--) {
            dp[j] = Math.max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return sum - dp[target] - dp[target];
};