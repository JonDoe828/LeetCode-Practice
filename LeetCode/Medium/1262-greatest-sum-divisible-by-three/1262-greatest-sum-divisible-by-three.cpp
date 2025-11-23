class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0; // 初始什么都不选，和为0，余数为0

        for (int x : nums) {
            vector<int> ndp = dp;
            for (int r = 0; r < 3; r++) {
                if (dp[r] != INT_MIN) {
                    int newSum = dp[r] + x;
                    int nr = newSum % 3;
                    ndp[nr] = max(ndp[nr], newSum);
                }
            }
            dp = ndp;
        }

        return dp[0];
    }
};