/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
// var maxUncrossedLines = function (nums1, nums2) {
//     let m = nums1.length, n = nums2.length;
//     const dp = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0))
//     for (let i = 1; i <= m; i++) {
//         for (let j = 1; j <= n; j++) {
//             if (nums1[i - 1] == nums2[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             else
//                 dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     return dp[m][n];
// };


function maxUncrossedLines(a, b) {
  let m = a.length, n = b.length;
  if (n > m) { [a, b] = [b, a]; [m, n] = [n, m]; } // 可选：保证 n ≤ m
  const dp = new Array(n + 1).fill(0);
  for (let i = 1; i <= m; i++) {
    let pre = 0; // 存 dp[i-1][j-1]
    for (let j = 1; j <= n; j++) {
      const tmp = dp[j]; // 暂存 dp[i-1][j]
      if (a[i - 1] === b[j - 1]) {
        dp[j] = pre + 1;
      } else {
        dp[j] = Math.max(dp[j], dp[j - 1]);
      }
      pre = tmp;
    }
  }
  return dp[n];
}