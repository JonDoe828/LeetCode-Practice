/**
 * @param {number[]} stones
 * @return {number}
 */
// var lastStoneWeightII = function (stones) {
//     const sum = stones.reduce((a, b) => a + b, 0)
//     const target = Math.floor(sum / 2); // 只取一半及以下
//     const dp = new Array(target + 1).fill(false);
//     dp[0] = true;

//     for (const x of stones) {
//         for (let w = target; w >= x; w--) {
//             dp[w] = dp[w] || dp[w - x];
//         }
//     }

//     for (let s = target; s >= 0; s--) {
//         if (dp[s]) return sum - 2 * s;
//     }
//     return 0;
// };


var lastStoneWeightII = function(stones) {
  const sum = stones.reduce((a, b) => a + b, 0);
  const target = Math.floor(sum / 2);
  let bits = 1n; // 只有和为0可达
  for (const x of stones) {
    bits |= (bits << BigInt(x));
  }
  // 从 target 往下找第一个可达的 s
  for (let s = target; s >= 0; s--) {
    if ((bits >> BigInt(s)) & 1n) return sum - 2 * s;
  }
  return 0;
};