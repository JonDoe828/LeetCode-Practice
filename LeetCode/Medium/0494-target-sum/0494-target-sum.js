/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var findTargetSumWays = function (nums, target) {
    const sum = nums.reduce((a, b) => a + b, 0)
    if (Math.abs(target) > sum) return 0;

    // sum(P) = (sum + target)/2
    if ((sum + target) % 2 === 1) return 0;

    const positive = (sum + target) >> 1;
    const dp = new Array(positive + 1).fill(0)
    dp[0] = 1;

    for (let i = 0; i < nums.length; i++) {
        for (let j = positive; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]]
        }
    }
    return dp[positive]
};