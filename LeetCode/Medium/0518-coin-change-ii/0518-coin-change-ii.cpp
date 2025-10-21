class Solution {
public:
    int change(int amount, vector<int>& coins) {
        using u128 = __uint128_t;              // GNU 扩展，LeetCode/Clang/GCC 通常可用
        vector<u128> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins) {
            for (int x = c; x <= amount; ++x) {
                dp[x] += dp[x - c];
            }
        }
        // 按题面返回 int；若你在自定义大数据上跑，可能会超 int
        if (dp[amount] > static_cast<u128>(numeric_limits<int>::max())) {
            // 你可以选择：返回 -1 / 截断 / 改函数签名
            // 这里示例：截断（与 LeetCode 答案类型兼容）
        }
        return static_cast<int>(dp[amount]);
    }
};