function combinationSum4(nums: number[], target: number): number {
    const dp: number[] = new Array(target + 1).fill(0);
    dp[0] = 1;
    for (let t = 1; t <= target; t++) {
        for (const x of nums) {
            if (t >= x) dp[t] += dp[t - x];
        }
    }
    return dp[target];
};