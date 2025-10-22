// function numSquares(n: number): number {
//     const dp = new Array<number>(n + 1).fill(n);
//     dp[0] = 0;
//     for (let i = 1; i <= n; i++) {
//         for (let j = 1; j * j <= i; j++) {
//             dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
//         }
//     }
//     return dp[n];
// };


function numSquares(n: number): number {
  const isSquare = (x: number) => {
    const r = Math.trunc(Math.sqrt(x));
    return r * r === x;
  };

  if (isSquare(n)) return 1;

  let m = n;
  while ((m & 3) === 0) m >>= 2; // 去掉4因子
  if (m % 8 === 7) return 4;

  for (let a = 1; a * a <= n; a++) {
    if (isSquare(n - a * a)) return 2;
  }
  return 3;
}