/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    // let cur = nums[0];  // dp[i-1]：以当前元素结尾的最大子数组和
    // let ans = nums[0];  // 全局最大

    // for (let i = 1; i < nums.length; i++) {
    //     // 状态转移方程
    //     cur = Math.max(nums[i], cur + nums[i]);
    //     ans = Math.max(ans, cur);
    // }

    // return ans;

    //前缀和 + 最小前缀和版
    if (nums.length === 0) return 0;

    let ans = -Infinity;
    let curPrefixSum = 0;
    let minPrefixSum = 0;  // 相当于 prefix[-1] = 0

    for (const num of nums) {
        curPrefixSum += num; // 当前前缀和
        ans = Math.max(ans, curPrefixSum - minPrefixSum); // 尝试以当前位置结尾的最大子数组
        minPrefixSum = Math.min(minPrefixSum, curPrefixSum); // 维护历史最小前缀和
    }

    return ans;
};