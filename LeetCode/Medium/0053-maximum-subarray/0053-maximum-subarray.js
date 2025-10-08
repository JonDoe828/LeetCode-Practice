/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    let cur = nums[0];  // dp[i-1]：以当前元素结尾的最大子数组和
    let ans = nums[0];  // 全局最大

    for (let i = 1; i < nums.length; i++) {
        // 状态转移方程
        cur = Math.max(nums[i], cur + nums[i]);
        ans = Math.max(ans, cur);
    }

    return ans;
};