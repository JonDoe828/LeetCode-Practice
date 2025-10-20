/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
    let sum = nums.reduce((a, b) => a + b, 0);
    if (sum % 2 !== 0) return false;
    const target = (sum / 2) | 0;

    // 可选剪枝：大数在前更快触达
    nums.sort((a, b) => b - a);
    if (nums[0] > target) return false;

    const dp = new Array(target + 1).fill(false);
    dp[0] = true;

    for (const x of nums) {
        for (let s = target; s >= x; s--) {
            if (!dp[s] && dp[s - x]) dp[s] = true;
        }
        if (dp[target]) return true; // 早停
    }
    return dp[target];
};