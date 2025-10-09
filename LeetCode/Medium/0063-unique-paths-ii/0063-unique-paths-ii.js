/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function (obstacleGrid) {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;

    // 如果起点或终点是障碍，直接返回 0
    if (obstacleGrid[0][0] === 1 || obstacleGrid[m - 1][n - 1] === 1) {
        return 0;
    }

    // 初始化二维 dp 数组
    const dp = Array.from({ length: m }, () => Array(n).fill(0));
    dp[0][0] = 1; // 起点

    // 第一列
    for (let i = 1; i < m; i++) {
        if (obstacleGrid[i][0] === 0) {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // 第一行
    for (let j = 1; j < n; j++) {
        if (obstacleGrid[0][j] === 0) {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // 其他格子
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (obstacleGrid[i][j] === 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
};