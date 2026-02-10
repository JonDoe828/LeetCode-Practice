class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1)
            return (int)nums.size();

        int preDiff = 0;
        int curDiff = 0;
        int result = 1; // 默认最右端是一个峰/谷

        for (int i = 0; i < (int)nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];

            if ((preDiff <= 0 && curDiff > 0) ||
                (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff; // 关键：只在摆动变化时更新，避免平坡误判
            }
        }
        return result;
    }
};


// class Solution {
// public:
//     int dp[1005][2];
//     int wiggleMaxLength(vector<int>& nums) {
//         memset(dp, 0, sizeof dp);
//         dp[0][0] = dp[0][1] = 1;
//         for (int i = 1; i < nums.size(); ++i) {
//             dp[i][0] = dp[i][1] = 1;
//             for (int j = 0; j < i; ++j) {
//                 if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
//             }
//             for (int j = 0; j < i; ++j) {
//                 if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
//             }
//         }
//         return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
//     }
// };