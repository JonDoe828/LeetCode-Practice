function findTargetSumWays(nums: number[], target: number): number {
    const sum = nums.reduce((a, b) => a + b, 0);
    if (target > sum) return 0;

    // sum(P) = (sum + target) / 2 必须是整数
    if (((sum + target) & 1) === 1) return 0;

    const positive = (sum + target) >> 1;   // “正号子集”的目标和
    const dp: number[] = new Array(positive + 1).fill(0);
    dp[0] = 1;

    for (let i = 0; i < nums.length; i++) {
        const x = nums[i];
        for (let j = positive; j >= x; j--) {
            dp[j] += dp[j - x];
        }
    }
    return dp[positive];
};