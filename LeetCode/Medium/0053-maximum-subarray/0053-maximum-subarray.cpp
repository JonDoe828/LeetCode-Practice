class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     if (nums.empty()) {
    //         return 0;
    //     }
    //     int ans = INT_MIN;
    //     int curPrefixsum = 0;
    //     int minPrefixSum = 0;
    //     for (int num : nums) {
    //         curPrefixsum += num;
    //         ans = max(ans, curPrefixsum - minPrefixSum);
    //         minPrefixSum = min(minPrefixSum, curPrefixsum);
    //     }
    //     return ans;
    // }

    //     int maxSubArray(vector<int>& nums) {
    //     int n = (int)nums.size();
    //     vector<int> dp(n);
    //     dp[0] = nums[0];
    //     int ans = dp[0];
    //     for (int i = 1; i < n; ++i) {
    //         dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    //         ans = max(ans, dp[i]);
    //     }
    //     return ans;
    // }

    // int maxSubArray(vector<int>& nums) {
    //     int cur = nums[0]; // 相当于 dp[i-1]
    //     int res = nums[0];
    //     for (int i = 1; i < (int)nums.size(); ++i) {
    //         cur = max(nums[i], cur + nums[i]); // dp[i]
    //         res = max(res, cur);
    //     }
    //     return res;
    // }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        int res = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};