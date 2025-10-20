/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
    const sum = nums.reduce((a, b) => a + b, 0);
    if (sum % 2 !== 0) return false;

    const target = sum / 2;
    const dp = new Array(target + 1).fill(0);
    
    for (const x of nums) {
        for (let j = target; j >= x; j--) {
            dp[j] = Math.max(dp[j], dp[j - x] + x);
        }
    }
    return dp[target] === target;
};