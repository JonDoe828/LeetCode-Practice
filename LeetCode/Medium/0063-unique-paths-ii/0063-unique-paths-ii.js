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

// var uniquePathsWithObstacles = function(obstacleGrid) {
//   const m = obstacleGrid.length;
//   const n = obstacleGrid[0].length;
//   const dp = new Array(n).fill(0);

//   // 初始化起点
//   dp[0] = obstacleGrid[0][0] === 0 ? 1 : 0;

//   for (let i = 0; i < m; i++) {
//     for (let j = 0; j < n; j++) {
//       // 如果当前位置是障碍，路径数置为 0
//       if (obstacleGrid[i][j] === 1) {
//         dp[j] = 0;
//       } else if (j > 0) {
//         // 当前格 = 来自上方（旧 dp[j]） + 左方（dp[j - 1]）
//         dp[j] += dp[j - 1];
//       }
//     }
//   }

//   return dp[n - 1];
// };