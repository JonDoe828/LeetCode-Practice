/**
 * @param {number} n
 * @return {number}
 */

var numTrees = function(n) {
  // G[m] 表示含 m 个节点能形成的不同 BST 个数
  const G = Array(n + 1).fill(0);

  // 空树算 1 种；n>=1 时，1 个节点也只有 1 种
  G[0] = 1;
  if (n >= 1) G[1] = 1;

  // 规模从小到大递推
  for (let m = 2; m <= n; m++) {
    for (let root = 1; root <= m; root++) {
      const leftSize = root - 1;   // 左子树节点数
      const rightSize = m - root;  // 右子树节点数
      // 左右子树独立组合，相乘后累加
      G[m] += G[leftSize] * G[rightSize];
    }
  }
  return G[n];
};

//卡特兰数迭代公式
// function numTrees(n) {
//   let c = 1; // C0
//   for (let k = 0; k < n; k++) {
//     c = (c * 2 * (2 * k + 1)) / (k + 2);
//   }
//   return Math.round(c); // 结果是整数，四舍五入防浮点毛刺
// }