/**
 * @param {number} n
 * @return {number}
 */
// var numTrees = function(n) {
//     const G = Array(n + 1).fill(0);
//     G[0] = 1; G[1] = 1;
//     for (let m = 2; m <= n; m++) {
//         for (let root = 1; root <= m; root++) {
//             G[m] += G[root - 1] * G[m - root];
//         }
//     }
//     return G[n];    
// };

function numTrees(n) {
  let c = 1; // C0
  for (let k = 0; k < n; k++) {
    c = (c * 2 * (2 * k + 1)) / (k + 2);
  }
  return Math.round(c); // 结果是整数，四舍五入防浮点毛刺
}