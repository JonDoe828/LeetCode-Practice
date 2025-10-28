class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int result1 = robRange(nums, 0, nums.size() - 2);
        int result2 = robRange(nums, 1, nums.size() - 1);
        return max(result1, result2);
    }

    int robRange(vector<int>& nums, int start, int end) {
        int n = (int)nums.size();
        if (end == start)
            return nums[start];
        vector<int> dp(n);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
};