function canPartition(nums: number[]): boolean {
    const sum = nums.reduce((a, b) => a + b, 0)
    if (sum % 2 !== 0) return false;
    const target = sum / 2

    const dp: number[] = new Array(target + 1).fill(0);

    for (const x of nums) {
        for (let j = target; j >= x; j--) {
            dp[j] = Math.max(dp[j], dp[j - x] + x);
        }
        // 可选早停：凑满了就直接返回
        if (dp[target] === target) return true;
    }
    return dp[target] === target;
};