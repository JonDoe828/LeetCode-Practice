/**
 * @param {number[]} nums
 * @return {boolean}
 */
// var canPartition = function (nums) {
//     const sum = nums.reduce((a, b) => a + b, 0);
//     if (sum % 2 !== 0) return false;

//     const target = sum / 2;
//     const dp = new Array(target + 1).fill(0);

//     for (const x of nums) {
//         for (let j = target; j >= x; j--) {
//             dp[j] = Math.max(dp[j], dp[j - x] + x);
//         }
//     }
//     return dp[target] === target;
// };

var canPartition = function(nums) {
  const sum = nums.reduce((a, b) => a + b, 0);
  if (sum & 1) return false;
  const target = sum / 2;

  // 剪枝
  let mx = 0;
  for (const x of nums) if (x > mx) mx = x;
  if (mx > target) return false;

  nums.sort((a, b) => b - a);

  // 一维 0/1 背包 + 早停
  const dp = new Uint16Array(target + 1); // 比普通 Array 更快更省内存（target<=20000）
  for (const x of nums) {
    for (let j = target; j >= x; --j) {
      const cand = dp[j - x] + x;
      if (cand > dp[j]) dp[j] = cand;
    }
    if (dp[target] === target) return true;
  }
  return dp[target] === target;
};


//最快
// var canPartition = function(nums) {
//   const sum = nums.reduce((a, b) => a + b, 0);
//   if (sum & 1) return false;
//   const target = sum / 2;

//   let bits = 1n; // 仅和0可达
//   for (const x of nums) {
//     bits |= (bits << BigInt(x));
//     // 早停：第 target 位已为 1
//     if ((bits >> BigInt(target)) & 1n) return true;
//   }
//   return ((bits >> BigInt(target)) & 1n) === 1n;
// };