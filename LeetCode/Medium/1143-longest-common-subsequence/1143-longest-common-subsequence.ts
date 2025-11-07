


export function longestCommonSubsequence(a: string, b: string): number {
  const n = b.length;
  const dp = new Array<number>(n + 1).fill(0);
  for (let i = 1; i <= a.length; i++) {
    let prev = 0; // dp[i-1][j-1]
    for (let j = 1; j <= n; j++) {
      const temp = dp[j]; // dp[i-1][j]
      if (a[i - 1] === b[j - 1]) {
        dp[j] = prev + 1;
      } else {
        dp[j] = Math.max(dp[j], dp[j - 1]);
      }
      prev = temp;
    }
  }
  return dp[n];
}