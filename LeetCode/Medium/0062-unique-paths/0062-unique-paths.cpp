class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] 表示从 (0,0) 走到 (i,j) 的路径数
        // 用 long long 做中间计算更稳妥（最后再转回 int 以匹配题目签名）
        vector<vector<long long>> dp(m, vector<long long>(n, 1));
        // 第 0 行/第 0 列已经全是 1（只能一直向右或一直向下）

        for (int i = 1; i < m; ++i) {        // 从第 1 行开始递推
            for (int j = 1; j < n; ++j) {    // 从第 1 列开始递推
                // 转移：来自上方 + 来自左方
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // 右下角即答案；题目返回类型是 int，这里做一次安全转换
        return static_cast<int>(dp[m - 1][n - 1]);
    }
};