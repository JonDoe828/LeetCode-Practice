/**
 * @param {number} n
 * @return {number}
 */
 
// var integerBreak = function (n) {
//     const dp = Array(n + 1).fill(0);
//     dp[2] = 1;

//     for (let i = 3; i <= n; i++) {
//         let best = 0;
//         for (let j = 1; j < i; j++) {
//             // either stop splitting right side, or keep splitting it
//             best = Math.max(best, j * (i - j), j * dp[i - j]);
//         }
//         dp[i] = best;
//     }
//     return dp[n];
// };

//greedy
function integerBreak(n) {
  if (n === 2) return 1;
  if (n === 3) return 2;

  let prod = 1;
  while (n > 4) { // keep taking 3s while it helps
    prod *= 3;
    n -= 3;
  }
  // now n is 2, 3, or 4; multiply it directly
  return prod * n; // handles 2/3/4 and the 3+1 -> 2+2 case implicitly
}